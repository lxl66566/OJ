// use std::string::String;
struct Solution;
impl Solution {
    pub fn are_sentences_similar(mut sentence1: String,mut sentence2: String) -> bool {
        let temp = overlap_strings(sentence1.as_str(), sentence2.as_str());
        sentence1 = sentence1.chars().rev().collect();
        sentence2 = sentence2.chars().rev().collect();
        let temp2 = overlap_strings(&sentence1.as_str(), &sentence2.as_str());
        println!("{temp} {temp2}");
        temp + temp2 >= std::cmp::min(sentence2.len(),sentence1.len()) as i32
    }
}
fn overlap_strings(a: &str, b: &str) -> i32 {
    let mut ait = a.chars().into_iter();
    let mut bit = b.chars().into_iter();
    let mut ans = 0;
    let mut flag = false;
    loop {
        let ai = ait.next();
        let bi = bit.next();
        if ai.is_none() || bi.is_none() {
            if (ai.is_none() && !bi.is_none() && bi.unwrap() == ' ') 
            || (!ai.is_none() && bi.is_none() && ai.unwrap() == ' ') {
                flag = true;
            }
            if flag { break; } else { return i32::MIN / 4; }
        }
        else if ai.unwrap() != bi.unwrap(){
            if flag { break; } else { return i32::MIN / 4; }
        }
        ans += 1;
        if ai.unwrap() != ' ' { flag = false; } else { flag = true; }
        }
    ans
}
fn main() {
    println!("{}",Solution::are_sentences_similar(String::from("DN PD"), String::from("D")));
}
