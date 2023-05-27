struct Solution;
impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut map = HashMap::new();
        time.into_iter().for_each(|t| {
            map.entry(t % 60).and_modify(|v| *v += 1).or_insert(1);
        });
        let mut ans = 0;
        dbg!(&map);
        map.iter()
            .filter(|&t| *t.0 < 30 && *t.0 > 0)
            .for_each(|(t, n)| ans += map.get(&(60 - t)).unwrap_or(&0) * n);
        if map.contains_key(&30) {
            let temp = map.get(&30).unwrap();
            ans += temp * (temp - 1) / 2;
        }
        if map.contains_key(&0) {
            let temp = map.get(&0).unwrap();
            ans += if temp % 2 == 0 {
                temp / 2 * (temp - 1)
            } else {
                (temp - 1) / 2 * temp
            };
        }
        ans
    }
}
fn main() {
    println!(
        "{:#?}",
        Solution::num_pairs_divisible_by60(vec![30, 20, 150, 100, 40])
    );
}
