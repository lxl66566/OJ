use std::collections::HashMap;
struct Solution;
impl Solution {
    pub fn decode_message(key: String,message: String) -> String {
        let mut map: HashMap<char,char> = HashMap::new();
        map.insert(' ', ' ');
        let mut i = b'a';
        for c in key.chars() {
            if c != ' '  && !map.contains_key(&c) {
                map.insert(c, i as char);
                i += 1;
                if i > b'z' { break; }
            }
        }
        message.chars().into_iter().map(|c| map.get(&c).unwrap()).collect()
    }
}
fn main() {
    println!("{:#?}",Solution::decode_message("the quick brown fox jumps over the lazy dog".to_owned(),"vkbs bs t suepuv".to_owned()));
}
