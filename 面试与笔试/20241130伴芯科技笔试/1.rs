//! 给出 N 个点（1..=N）和 M 个数字对 (a, b)，表示 a 点和 b 点**不能**被分在一组。求最少需要分多少组，可以满足需求。
//! 这玩意其实是 [Welsh–Powell 算法](https://oi-wiki.org/graph/color/#welshpowell-%E7%AE%97%E6%B3%95)，我之前没听过，但是笔试就自己写出来了。

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct Point {
    pub x: i32,
    pub y: i32,
}

impl Point {
    #[inline]
    fn new(x: i32, y: i32) -> Self {
        Point { x, y }
    }
}

use std::collections::HashSet;
use std::iter::FromIterator;
struct Solution {}
#[derive(Debug, PartialEq, Eq, Default, Clone)]
struct Me(HashSet<i32>, i32);

impl PartialOrd for Me {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        self.0.len().partial_cmp(&other.0.len())
    }
}
impl Ord for Me {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.0.len().cmp(&other.0.len())
    }
}
impl Me {
    fn new(n: i32) -> Self {
        Self(HashSet::new(), n)
    }
}

impl Solution {
    fn new() -> Self {
        Solution {}
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param N int整型 节点总数
     * @param constraints Point类一维数组 约束边
     * @return int整型二维数组
     */
    pub fn grouping(&self, N: i32, constraints: Vec<Point>) -> Vec<Vec<i32>> {
        let mut mes = Vec::from_iter((0..N).map(Me::new));
        let mut used = vec![false; N as usize];
        let mut used_num = 0;
        for p in constraints {
            mes.get_mut((p.x - 1) as usize).unwrap().0.insert(p.y - 1);
            mes.get_mut((p.y - 1) as usize).unwrap().0.insert(p.x - 1);
        }
        mes.sort_unstable_by(|a, b| b.cmp(a));
        let mut begin_index = 0;
        let mut ans = vec![];
        while used_num < N {
            let mut this = vec![];
            let mut no_together: HashSet<i32> = HashSet::new();
            for (index, v) in mes.iter().enumerate().skip(begin_index) {
                if used[index] {
                    continue;
                }
                if this.is_empty() {
                    this.push(index as i32 + 1);
                    used[index] = true;
                    used_num += 1;
                    begin_index = index + 1;
                    no_together.extend(v.0.iter());
                    continue;
                }
                // dbg!(&no_together);
                if no_together.contains(&{ v.1 }) {
                    continue;
                } else {
                    this.push(index as i32 + 1);
                    used[index] = true;
                    used_num += 1;
                    no_together.extend(v.0.iter());
                }
            }
            ans.push(this);
        }
        ans
    }
}

fn main() {
    let s = Solution {};
    println!(
        "{:?}",
        s.grouping(4, vec![Point::new(1, 2), Point::new(3, 4)])
    );
    println!(
        "{:?}",
        s.grouping(3, vec![Point::new(1, 2), Point::new(1, 3)])
    );
    println!(
        "{:?}",
        s.grouping(
            3,
            vec![Point::new(1, 2), Point::new(1, 3), Point::new(2, 3)]
        )
    );
}
