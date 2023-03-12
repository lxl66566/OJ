struct Solution;
use std::collections::{ BTreeSet, HashMap };
#[allow(non_camel_case_types)]
trait feature<T> {
    fn last(&self) -> Option<&T>;
    fn first(&self) -> Option<&T>;
}
impl<T: std::cmp::Ord> feature<T> for BTreeSet<T> {
    fn last(&self) -> Option<&T> {
        // self.range(..).last()
        self.iter().next()
    }
    fn first(&self) -> Option<&T> {
        self.iter().rev().next()
    }
}
impl Solution {
    pub fn find_longest_subarray(array: Vec<String>) -> Vec<String> {
        let mut buc: HashMap<i32,BTreeSet<usize>> = HashMap::new();
        let mut now = 0;
        array.iter().enumerate().for_each(|(i,x)|{
            assert!(!x.is_empty());
            if x.chars().next().unwrap().is_ascii_digit() {
                now += 1;
            }
            else { now -= 1; }
            buc.entry(now).or_insert(BTreeSet::new()).insert(i);
        });
        let (mut ans,mut first,mut last) = (0,0,0);
        buc.into_iter().for_each(|(i,v)| ->  {
            if i == 0
            {
                if let Some(x) = buc.get(&0)?.last(){
                    ans = *x + 1;
                    last = *x;
                }
                return None;
            }
            if v.len() < 2 { return None; }
            let temp = v.last().unwrap() - v.first().unwrap();
            if temp > ans || (temp == ans && *v.first().unwrap() < first) {
                ans = temp;
                first = *v.first().unwrap();
                last = *v.last().unwrap();
            }
            None
        });
        if ans != 0 { array[if (last - first) % 2 != 0 { first } else { first + 1 } ..=last].to_vec() } else { vec![] }
    }
}
fn main() {
    println!("{:#?}",Solution::find_longest_subarray(vec!["36","86","w","17","81","W","64","97","S","s","32","61","W","I","99","X","W","l","33","L","17","G","27","70","37","5","62","W","x","39","58","16","Z","46","X","o","45","G","63","q","16","C","E","n","w","93","35","J","L","62","11","95","11","7","89","c","0","41","J","X","w","41","d","62","8","65","m","K","85","A","V","16","92","48","35","91","18","F","13","18","p","0","88","8","5","75","62","83","34","27","15","79","52","r","t","49","w","G","S","18"]
    .into_iter().map(|x| x.to_string()).collect()));
}
