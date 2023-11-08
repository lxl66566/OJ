struct Solution;
impl Solution {
    pub fn best_hand(mut ranks: Vec<i32>, suits: Vec<char>) -> String {
        assert_eq!(ranks.len(),5);
        assert_eq!(suits.len(),5);
        ranks.sort_unstable();
        let ch = suits[0];
        if suits.iter().all(|&c| c == ch) {
            return "Flush".to_string();
        }
        let same = |x:i32,y:i32,z:i32| {x == y && y == z};
        if same(ranks[0],ranks[1],ranks[2]) || same(ranks[1],ranks[2],ranks[3]) ||
         same(ranks[2],ranks[3],ranks[4]){
            return "Three of a Kind".to_string();
        }
        if ranks[0] == ranks[1] || ranks[1] == ranks[2] || ranks[2] == ranks[3] || ranks[3] == ranks[4]{
            return "Pair".to_string();
        }
        "High Card".to_string()
        
    }
}
fn main() {
    println!("{:#?}",Solution::best_hand(vec![13,2,3,1,9], vec!['b','d','b','c','b']));
}
