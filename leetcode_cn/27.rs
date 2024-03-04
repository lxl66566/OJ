struct Solution;
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        for j in 0..nums.len() {
            let n = nums[j];
            if n != val {
                nums[i] = n;
                i += 1;
            }
        }
        i as i32
    }
}

fn main() {
    let mut vec = vec![3, 2, 2, 3, 2, 3];
    println!("{:#?}", Solution::remove_element(&mut vec, 3));
    println!("{:#?}", vec);
}
