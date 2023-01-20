use std::collections::HashMap;
struct Solution;
impl Solution {
    pub fn finding_users_active_minutes(mut logs: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut ans = vec![0;k as usize];
        let mut map: HashMap<i32, i32> = HashMap::new();
        logs.sort_by_key(|k| k[0]);
        dbg!(&logs);
        let mut now = logs[0][0];
        for i in logs
        {
            if i[0] != now 
            {
                now = i[0];
                ans[map.len() - 1] += 1;
                map.clear();
            }
            map.insert(i[1], 1);
        }
        ans[map.len() - 1] += 1;
        ans
    }
}
fn main() {
    println!("{:?}",Solution::finding_users_active_minutes(vec![vec![0,5],vec![1,2],vec![0,2],vec![0,5],vec![1,3]], 5));
}
// 执行用时：216 ms, 在所有 Rust 提交中击败了 100.00% 的用户
// 内存消耗：3.2 MB, 在所有 Rust 提交中击败了 100.00% 的用户