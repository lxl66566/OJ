//! 输入： a, b
//! 从 1 开始，每次可以：
//! 1. 乘 a
//! 2. 循环移位任意次数，例如 54321 --> 43215 或 32154 或 21543 等等
//! 输出：最少多少次可以达到 b，如果不行，输出 -1
//!
//! 此代码为 AC 代码。

fn mov(mut x: u32) -> Vec<u32> {
    let mut x_c = x;
    let mut bits = 0;
    while x_c > 0 {
        x_c = x_c / 10;
        bits += 1;
    }
    let mut res = Vec::new();
    for _ in 0..bits - 1 {
        let y = x % 10;
        x = y * 10_u32.pow(bits - 1) + x / 10;
        res.push(x);
    }
    res.dedup();
    res
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("failed to read");
    let res = s
        .trim()
        .split_ascii_whitespace()
        .map(|x| x.parse::<u32>().unwrap())
        .collect::<Vec<u32>>();
    let (a, b) = (res[0], res[1]);
    if b == 1 {
        println!("0");
        return;
    }
    let mut iter = vec![(b, 0)];
    let mut set = std::collections::BTreeSet::from([b]);
    loop {
        dbg!(&iter);
        iter = iter
            .into_iter()
            .map(|(x, t)| mov(x).into_iter().map(move |y| (y, t + 1)).chain([(x, t)]))
            .flatten()
            .filter_map(|(x, t)| {
                if x % a == 0 {
                    Some((x / a, t + 1))
                } else {
                    None
                }
            })
            .filter(|x| !set.contains(&x.0))
            .collect::<Vec<_>>();
        iter.iter().for_each(|(x, _)| {
            set.insert(*x);
        });
        if iter.len() == 0 {
            println!("-1");
            break;
        }
        if let Some(ans) = iter.iter().find(|x| x.0 == a) {
            println!("{}", ans.1 + 1);
            break;
        }
    }
}

#[test]
fn test() {
    println!("{:?}", mov(1));
}
