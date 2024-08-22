struct Solution;
impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        let mut n = n as u64;
        let mut poss = vec![];
        for i in 0..32 {
            if (1 << i) > x {
                break;
            }
            if x & (1 << i) > 0 {
                poss.push(i);
            }
        }
        // dbg!(&poss);
        n = n - 1;
        for i in poss.into_iter() {
            n = Solution::insert_to(n, i);
        }
        n as i64
    }

    fn insert_to(mut n: u64, pos: usize) -> u64 {
        // 1011 -> insert 1 to 3 -> 11011
        if pos == 0 {
            return (n << 1) + 1;
        }
        let mask = (1 << pos) - 1; // 00111
        let l = (n & !mask | (1 << (pos - 1))) << 1;
        let r = n & mask;
        l | r
    }
}

fn main() {
    println!("{}", Solution::min_end(3, 4));
    println!("{}", Solution::min_end(2, 7));
    println!("{}", Solution::min_end(6715154, 7193485));
}

#[test]
fn test_insert_to() {
    assert_eq!(Solution::insert_to(0b1011, 4), 0b11011);
    assert_eq!(Solution::insert_to(0b1011, 3), 0b11011);
    assert_eq!(Solution::insert_to(0b1011, 2), 0b10111);
    assert_eq!(Solution::insert_to(0b1011, 1), 0b10111);
    assert_eq!(Solution::insert_to(0b1011, 0), 0b10111);
}
