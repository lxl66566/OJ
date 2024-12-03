//! s 个数字满足 sum(s) % p == 0，求其最小子集 t 也满足 sum(t) % p == 0。len(s) <= 10^7, p < 100

use std::{collections::BTreeMap, iter};

fn solve(s: &[i32], p: i32) -> Vec<i32> {
    let mut dp = BTreeMap::new();
    // key: 当前选择的元素 sum % p, value: 尚未使用的 s
    dp.insert(0_usize, s.to_vec());
    loop {
        let mut new_dp = dp.clone();
        dp.into_iter().for_each(|(index, v)| {
            for j in 0..v.len() {
                let mut temp_vec = v.to_vec();
                let new_index = ((index as i32 + temp_vec[j])/*% p*/) as usize;
                temp_vec.remove(j);
                if let Some(old_val) = new_dp.get_mut(&new_index) {
                    if old_val.len() > temp_vec.len() {
                        _ = std::mem::replace(old_val, temp_vec);
                    }
                } else {
                    new_dp.insert(new_index, temp_vec);
                }
            }
        });
        dp = new_dp;
        for i in 1..s.len() {
            let check_idx = i * p as usize;
            if dp.contains_key(&check_idx) {
                // dbg!(&dp);
                let not_used = dp.get(&check_idx).unwrap();
                let mut s_map = BTreeMap::new();
                s.iter().for_each(|x| *s_map.entry(x).or_insert(0) += 1);
                not_used
                    .iter()
                    .for_each(|n| *s_map.get_mut(n).unwrap() -= 1);
                let mut res = vec![];
                s_map
                    .into_iter()
                    .for_each(|(index, x)| res.extend(iter::once(index).cycle().take(x)));
                return res;
            }
        }
    }
}

fn main() {
    let s = vec![1, 2, 3, 4];
    let p = 5;
    dbg!(solve(&s, p));
    let s = vec![1, 2, 3, 4, 5];
    dbg!(solve(&s, p));
    let s = vec![1, 2, 6, 7, 12, 17];
    dbg!(solve(&s, p));
    let s = vec![1, 2, 6, 7, 11, 12, 13, 14, 17, 22];
    dbg!(solve(&s, p));
}
