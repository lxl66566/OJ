struct Solution;
impl Solution {
    pub fn balanced_string(s: String) -> i32 {
        let lec: i32 = (s.len() / 4) as i32;
        let mut calc: Vec<i32> = vec![0; 4];
        let map = |c: char| -> usize {
            match c {
                'Q' => 0,
                'W' => 1,
                'E' => 2,
                _ => 3,
            }
        };
        let mut ans = 0;
        for c in s.chars() {
            if calc[map(c)] < lec {
                calc[map(c)] += 1;
                ans += 1;
            }
            else { break; }
        }
        dbg!(&calc);
        for c in s.chars().rev() {
            if calc[map(c)] < lec {
                calc[map(c)] += 1;
                ans += 1;
            }
            else { break; }
        }
        (s.len() as i32 - ans).max(0)
    }
}
fn main() {
    println!("{:#?}",Solution::balanced_string(String::from("WWEQERQWQWWRWWERQWEQ")));
}
