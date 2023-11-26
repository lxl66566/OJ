struct Solution;
// 自己做想不到。。感觉这题需要脑子灵活。
impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        fn validate(i: usize, nums: &Vec<i32>) -> bool {
            nums[i] <= 0 || nums[i] > nums.len() as i32 || nums[i] == i as i32 + 1
        }
        for i in 0..nums.len() {
            while !validate(i, &nums) {
                let temp: usize = (nums[i] - 1) as usize;
                if nums[i] == nums[temp] {
                    break;
                }
                nums.swap(i, temp);
            }
        }
        // eprintln!("{:#?}", nums);
        for (i, j) in nums.iter().enumerate() {
            if i as i32 != *j - 1 {
                return i as i32 + 1;
            }
        }
        nums.len() as i32 + 1
    }
}
fn main() {
    let nums1 = vec![1, 1];
    println!("{:#?}", Solution::first_missing_positive(nums1));
}
