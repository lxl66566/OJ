use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if s.is_empty() {
            return 0;
        }
        let mut ans = 0;
        let mut window = HashMap::new();
        let (mut front, mut back) = (-1_i32, 0);
        let s = s.as_bytes();
        for i in 0..s.len() {
            while *window.entry(&s[i]).or_insert(0) > 0 {
                *window.get_mut(&s[back as usize]).unwrap() -= 1;
                back += 1;
            }
            front += 1;
            *window.entry(&s[i]).or_insert(0) += 1;
            ans = ans.max(front - back + 1);
        }
        ans
    }
}
fn main() {
    dbg!(Solution::length_of_longest_substring("abcabcbb".into()));
    dbg!(Solution::length_of_longest_substring("bbbbb".into()));
    dbg!(Solution::length_of_longest_substring("".into()));
    dbg!(Solution::length_of_longest_substring(" ".into()));
}
