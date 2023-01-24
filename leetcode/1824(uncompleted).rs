struct Solution;impl Solution {
    pub fn min_side_jumps(obstacles: Vec<i32>) -> i32 {
        let mut now = 2;
        let mut ans = 0;
        let mut iter = obstacles.iter();
        let mut last = 0;
        loop {
            // iter.find(|&&x| x == now);
            let mut next = *iter.next().unwrap_or(&-1);
            while next != now {
                last = next;
                next = *iter.next().unwrap_or(&-1);
            }
            if last != 0 
            {
                now = *[1,2,3].iter().filter(|&&y| y != now && y != last).next().unwrap();
                if next == -1 { break; }
                continue;
            }
            let temp = iter.find(|&&x| x != now && x != 0);
            // dbg!(temp);
            match temp {
                Some(&x) => {
                    now = *[1,2,3].iter().filter(|&&y| y != now && y != x).next().unwrap();
                    ans += 1;
                }
                _ => {
                    break;
                }
            }
            dbg!(now);
        }
        ans
    }
}
fn main() {
    println!("{}",Solution::min_side_jumps(vec![0,1,2,3,0]));
}