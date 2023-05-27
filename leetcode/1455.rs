impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let ret = -1;
        let mut cur = 0;
        for w in sentence.split(' '){
            cur += 1;
            if w.starts_with(&search_word){
                return cur;
            }
        }
        ret
    }
}