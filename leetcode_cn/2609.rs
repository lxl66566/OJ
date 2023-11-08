struct Solution;
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let (mut status, mut zeros, mut ones) = (0, 0, 0);
        let mut max = 0;
        for i in (s + "0").chars() {
            dbg!(i);
            if i == '0' {
                if status == 1 {
                    status = 0;
                    max = max.max(zeros.min(ones) * 2);
                    zeros = 0;
                    ones = 0;
                }
                zeros += 1;
            } else {
                status = 1;
                ones += 1;
            }
        }
        max
    }
}
fn main() {
    println!(
        "{:#?}",
        Solution::find_the_longest_balanced_substring("011000111".to_owned())
    );
}
