struct Solution;
impl Solution {
    pub fn capitalize_title(title: String) -> String {
        let mut ans = String::new();
        for word in title.split_ascii_whitespace() {
            if word.len() < 3 {
                ans.push_str(word.to_lowercase().as_str());
            } else {
                let mut iter = word.chars();
                ans.push(iter.next().unwrap().to_ascii_uppercase());
                iter.for_each(|c| ans.push(c.to_ascii_lowercase()));
            }
            ans.push(' ');
        }
        ans.pop();
        ans
    }
}
fn main() {
    println!(
        "{:#?}",
        Solution::capitalize_title("capiTalIze tHe titLe".into())
    );
}
