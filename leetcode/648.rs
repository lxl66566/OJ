struct Solution;
impl Solution {
    pub fn replace_words(mut dictionary: Vec<String>, sentence: String) -> String {
        let mut words = sentence.split(' ').collect::<Vec<&str>>();
        dictionary.sort_unstable_by(|a, b| a.len().cmp(&b.len()));
        for i in 0..words.len() {
            let word = words[i];
            for pat in dictionary.iter() {
                let temp = pat.as_str();
                if word.starts_with(temp) {
                    words[i] = temp;
                    break;
                }
            }
        }
        words.join(" ")
    }
}
fn main() {
    println!("{:#?}",Solution::replace_words
    (vec!["a".to_string(), "aa".to_string(), "aaa".to_string(), "aaaa".to_string()], "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa".to_string()));
}
