use std::mem::swap;

struct Solution;
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        assert!(!nums.is_empty());
        let size = nums.len();
        let k = (k % size as i32) as usize;
        let mut temp = nums[0];
        if k == 0 {
            return;
        }
        let mut i = 0;
        let mut times = 0;
        let mut start = 0;
        while times < size {
            // dbg!(&nums);
            i = (i + k) % size;
            times += 1;
            swap(&mut nums[i], &mut temp);
            if i == start {
                i += 1;
                start = i;
                temp = nums[i];
            }
            // dbg!(format!("swap {} and {}", nums[i], temp));
        }
    }
}
fn main() {
    let mut a = vec![1, 2, 3, 4, 5, 6, 7];
    Solution::rotate(&mut a, 3);
    println!("{:#?}", a);
    let mut a: Vec<i32> = (1..=10).collect();
    Solution::rotate(&mut a, 5);
    println!("{:#?}", a);
}
