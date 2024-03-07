struct Solution;
impl Solution {
    pub fn divisibility_array(word: String, m: i32) -> Vec<i32> {
        let m = m as i64;
        let mut ans: Vec<i32> = Vec::new();
        let mut now: i64 = 0;
        for w in word.chars() {
            now = (now * 10 + (w as i64 - '0' as i64)) % m;
            ans.push(if now == 0 { 1 } else { 0 });
        }
        ans
    }
}

fn main() {
    println!(
        "{:#?}",
        Solution::divisibility_array("34654610689498".into(), 3)
    );
}
