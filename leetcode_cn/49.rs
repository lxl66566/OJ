use std::collections::{BTreeMap, HashMap};

struct Solution;

impl Solution {
    pub fn preprocess(s: &str) -> BTreeMap<char, i32> {
        let mut d: BTreeMap<char, i32> = BTreeMap::new();
        for i in s.chars() {
            *d.entry(i).or_insert(0) += 1;
        }
        d
    }
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut dct: HashMap<BTreeMap<char, i32>, Vec<String>> = HashMap::new();
        for s in strs.into_iter() {
            let tmp = Self::preprocess(&s);
            dct.entry(tmp).or_insert(vec![]).push(s);
        }
        dct.into_values().collect()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::group_anagrams(vec![
            "eat".to_string(),
            "tea".to_string(),
            "tan".to_string(),
            "ate".to_string(),
            "nat".to_string(),
            "bat".to_string()
        ])
    );
    println!(
        "{:?}",
        Solution::group_anagrams(vec!["ddddddddddg".to_string(), "dgggggggggg".to_string()])
    );
}
