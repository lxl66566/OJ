struct Solution;
impl Solution {
    pub fn most_competitive(nums: Vec<i32>, mut k: i32) -> Vec<i32> {
        let len = nums.len();
        if k == len as i32 {
            return nums;
        }
        let nums_origin = nums.clone();
        let mut nums = nums.into_iter().enumerate().collect::<Vec<_>>();
        nums.sort_by(|a, b| a.1.cmp(&b.1));
        let mut ans = Vec::new();
        let mut only_after_this_pos = -1;
        for i in &nums {
            if (len - i.0) as i32 >= k && i.0 as i32 > only_after_this_pos {
                ans.push(i.1);
                k -= 1;
                only_after_this_pos = i.0 as i32;
                if k == 0 {
                    break;
                }
            }
        }
        while k > 0 {
            k -= 1;
            only_after_this_pos += 1;
            ans.push(*nums_origin.get(only_after_this_pos as usize).unwrap());
        }
        ans
    }
}

fn main() {
    dbg!(Solution::most_competitive(vec![3, 5, 2, 6], 2));
    dbg!(Solution::most_competitive(vec![2, 4, 3, 3, 5, 4, 9, 6], 4));
    dbg!(Solution::most_competitive(
        vec![71, 18, 52, 29, 55, 73, 24, 42, 66, 8, 80, 2],
        3
    ));
}
