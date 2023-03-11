struct Solution;
impl Solution {
    pub fn find_longest_subarray(array: Vec<String>) -> Vec<String> {
        use std::collections::{ BTreeSet, HashMap };
        let mut buc: HashMap<i32,BTreeSet<usize>> = HashMap::new();
        let mut now = 0;
        array.iter().enumerate().for_each(|(i,x)|{
            assert!(!x.is_empty());
            if x.chars().next().unwrap().is_ascii_digit() {
                now += 1;
            }
            else { now -= 1; }
            // dbg!(now);
            if !buc.contains_key(&now) {
                buc.insert(now, BTreeSet::new());
            }
            buc.get_mut(&now).unwrap().insert(i);
        });
        dbg!(&buc);
        let (mut ans,mut first,mut last) = (0,0,0);
        if let Some(x) = buc.get(&0).unwrap_or(&BTreeSet::new()).last(){
            ans = *x + 1;
            last = *x;
        }
        buc.into_iter().for_each(|(_,v)|{
            if v.len() < 2 { return; }
            let temp = v.last().unwrap() - v.first().unwrap();
            if temp > ans {
                ans = temp;
                first = *v.first().unwrap();
                last = *v.last().unwrap();
            }
        });
        dbg!(&ans,&first,&last);
        if last > first{
            array[first..=last].to_vec()
        }
        else {
            vec![]
        }
    }
}
fn main() {
    println!("{:#?}",Solution::find_longest_subarray(vec!["A","1"].into_iter().map(|x| x.to_string()).collect()));
}
