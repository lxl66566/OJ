struct Solution;
use std::collections::VecDeque;
// 我使用一个 VecDeque 充当 "swap" 空间。想复杂了。
impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        if n == 0 {
            return;
        }
        if m == 0 {
            for (i, num) in nums2.iter().enumerate() {
                nums1[i] = *num;
            }
            return;
        }
        let mut t: VecDeque<i32> = VecDeque::from(vec![nums1[0]]);
        // let mut flag = false;
        let (mut i1, mut i2) = (0_usize, 0_usize);
        loop {
            if !t.is_empty() {
                // flag = true;
                let i = *t.front().unwrap();
                if i <= nums2[i2] {
                    nums1[i1] = i;
                    t.pop_front();
                    i1 += 1;
                    if i1 < m as usize {
                        t.push_back(nums1[i1]);
                    }
                } else {
                    nums1[i1] = nums2[i2];
                    i2 += 1;
                    i1 += 1;
                    if i1 < m as usize {
                        t.push_back(nums1[i1]);
                    }
                }
            } else {
                let i = nums1[i1];
                if i > nums2[i2] {
                    nums1[i1] = nums2[i2];
                    i1 += 1;
                    i2 += 1;
                    t.push_back(nums1[i1]);
                } else {
                    i1 += 1;
                }
            }
            dbg!(i1, i2);
            eprintln!("nums1 = {:#?}, vec = {:#?}", &nums1, &t);
            if i1 as i32 > n + m - 1 || i2 as i32 > n - 1
            /*|| (flag && t.is_empty())*/
            {
                break;
            }
        }
        while i2 < n as usize {
            nums1[m as usize + i2] = nums2[i2];
            i2 += 1;
        }
        while !t.is_empty() {
            nums1[i1 as usize] = t.pop_front().unwrap();
            i1 += 1;
            if i1 < (m + n) as usize && nums1[i1 as usize] != 0 {
                t.push_back(nums1[i1 as usize])
            }
        }
    }
}
fn main() {
    let mut nums1 = vec![1, 2, 4, 5, 6, 0];
    let mut nums2 = vec![3];
    Solution::merge(&mut nums1, 5, &mut nums2, 1);
    println!("{:#?}", nums1);
}
