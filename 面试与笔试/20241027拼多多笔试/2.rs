// 第二题 ~~neta 了中国和美国~~，说的是 C 国和 A 国在奥运会拿金牌。有若干项目，每个项目给出 C 国拿金牌的概率和 A 国拿金牌的概率（存在都不拿金牌的情况），求最终 C 国金牌数 > A 国金牌数的概率。
use std::collections::BTreeMap;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n: u32 = s.trim().parse().unwrap();
    let mut data = BTreeMap::new();
    data.insert(0, 1.0);
    for _ in 0..n {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut tmp = s.trim().split_ascii_whitespace();
        let x1: f64 = tmp.next().unwrap().parse().unwrap();
        let x2: f64 = tmp.next().unwrap().parse().unwrap();
        let mid = 1.0 - x1 - x2;
        let mut new_dat = BTreeMap::new();
        data.into_iter().for_each(|(i, od)| {
            *new_dat.entry(i + 1).or_insert(0.0_f64) += od * x1;
            *new_dat.entry(i).or_insert(0.0_f64) += od * mid;
            *new_dat.entry(i - 1).or_insert(0.0_f64) += od * x2;
        });
        data = new_dat;
    }
    let ans: f64 = data
        .into_iter()
        .filter_map(|it| if it.0 > 0 { Some(it.1) } else { None })
        .sum();
    println!("{:.3}", ans);
}
