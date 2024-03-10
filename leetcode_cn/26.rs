struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i = 0;
        if nums.is_empty() {
            return 0;
        }
        for j in 1..nums.len() {
            if nums[j] != nums[j - 1] {
                i += 1;
            }
            nums[i] = nums[j];
        }
        (i + 1) as _
    }
}

fn main() {
    let mut i = vec![1, 1, 2];
    println!("{:#?}", Solution::remove_duplicates(&mut i));
    dbg!(i);
}
