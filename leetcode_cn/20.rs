use std::collections::VecDeque;
struct Solution;
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut q: VecDeque<char> = VecDeque::new();
        let mut flag = true;
        for c in s.chars()
        {
            if c == '(' || c == '[' || c == '{' {
                q.push_back(c);
            }
            else
            {
                if (c == ')' && *q.back().unwrap_or(&' ') != '(') 
                || (c == ']' && *q.back().unwrap_or(&' ') != '[')
                || (c == '}' && *q.back().unwrap_or(&' ') != '{') {
                    flag = false;
                    break;
                }
                q.pop_back();
            }
        }
        if q.len() != 0 { flag = false; }
        flag
    }
}
fn main() {
    println!("{:?}",Solution::is_valid(String::from("[(({})}]")));
}