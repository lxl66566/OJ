//! 输入：第一行为一个数字代表数据组数。
//! 之后是一个 3*3 九宫格，每个格一个数字。可能为 0 - 9。
//! 你需要填入空缺的数字，让每个数字与其相邻的数字之差在 2 或以上。
//! 返回填法数量。
//!
//! 例如：
//! 1 3 5
//! 4 8 2
//! 0 6 0
//! 可以在两个 0 上任意填入 2 和 9，所以有两种填法。输出 2。

use std::collections::BTreeSet;

static DIRECTIONS: [(i32, i32); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

fn solve(v: Vec<Vec<u32>>) -> u32 {
    let mut to_fill: BTreeSet<u32> = (1..=9).collect();
    let mut zeros_pos = Vec::new();
    for i in 0..3 {
        for j in 0..3 {
            if v[i][j] == 0 {
                zeros_pos.push((i, j));
            } else {
                to_fill.remove(&v[i][j]);
            }
        }
    }
    let mut ans = 0;
    dfs(v, zeros_pos, to_fill, &mut ans);
    ans
}

fn dfs(v: Vec<Vec<u32>>, mut zeros: Vec<(usize, usize)>, nums: BTreeSet<u32>, ans: &mut u32) {
    if zeros.is_empty() {
        *ans += 1;
        return;
    }

    let (i, j) = zeros.pop().unwrap();
    for x in nums.clone() {
        let mut ano = nums.clone();
        let mut new_v = v.clone();
        ano.remove(&x);
        if check(&v, &(i, j), x) {
            new_v[i][j] = x;
            dfs(new_v, zeros.clone(), ano, ans);
        }
    }
}

fn check(v: &Vec<Vec<u32>>, pos: &(usize, usize), to_fill: u32) -> bool {
    let (i, j) = pos;
    for (di, dj) in DIRECTIONS {
        let ni = *i as i32 + di;
        let nj = *j as i32 + dj;
        if !(0..3).contains(&ni) || !(0..3).contains(&nj) {
            continue;
        }
        if abs_diff(to_fill, v[ni as usize][nj as usize]) == 1 {
            return false;
        }
    }
    true
}

#[inline]
fn abs_diff(x: u32, y: u32) -> u32 {
    if x > y {
        x - y
    } else {
        y - x
    }
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("failed to read");
    let n = s.trim().parse().unwrap();
    for _ in 0..n {
        let mut v = Vec::new();
        for _ in 0..3 {
            s = String::new();
            std::io::stdin().read_line(&mut s).expect("failed to read");
            let res = s
                .trim()
                .split_ascii_whitespace()
                .map(|x| x.parse::<u32>().unwrap())
                .collect::<Vec<u32>>();
            v.push(res);
        }
        println!("{}", solve(v));
    }
}
