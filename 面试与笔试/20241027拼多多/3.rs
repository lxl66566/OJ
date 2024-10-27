// 模拟哈希表，哈希函数 `f(x) = x % n`，如果哈希冲突就循环顺延；塞满了就不塞了。给一个入队序列，求最终状态。（注意，哈希表中添加相同元素会跳过添加）
use std::{collections::BTreeSet, iter};

#[inline]
fn find_insert_pos(v: &[i64], num: u64, next: &mut Vec<usize>) -> usize {
    let mut exp = num as usize % v.len();
    let mut lasts = vec![];
    loop {
        if v[exp] == -1 {
            for i in lasts {
                next[i] = next[exp];
            }
            return exp;
        }
        lasts.push(exp);
        exp = next[exp];
    }
}

fn solution(n: usize, s: String) -> Vec<i64> {
    let mut arr = vec![-1; n];
    let mut size = n;
    let mut inserted = BTreeSet::new();
    let mut next: Vec<usize> = (1..arr.len()).chain(iter::once(0)).collect();
    for i in s.trim().split_ascii_whitespace() {
        if size == 0 {
            break;
        }
        let i: u64 = i.parse().unwrap();
        if inserted.contains(&i) {
            continue;
        } else {
            inserted.insert(i);
        }
        let index = find_insert_pos(&arr, i, &mut next);
        arr[index] = i as i64;
        size -= 1;
    }
    arr
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut tmp = s.trim().split_ascii_whitespace();
    let _: usize = tmp.next().unwrap().parse().unwrap();
    let n: usize = tmp.next().unwrap().parse().unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();

    let arr = solution(n, s);
    arr.into_iter().for_each(|x| print!("{} ", x));
}

#[test]
fn test() {
    dbg!(solution(2, "3 3 6 7 8".into()));
}
