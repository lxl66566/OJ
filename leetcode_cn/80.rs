struct Solution;
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i = 0;
        let mut last_same = 0;
        for j in 0..nums.len() {
            let n = nums[j];
            if nums[last_same] != n {
                last_same = j;
            }
            if j - last_same < 2 {
                nums[i] = n;
                i += 1;
            }
        }
        i as i32
    }
}

fn main() {
    let mut vec = vec![1, 2, 2, 2, 2, 3, 3, 3, 4, 6, 6, 6, 6, 6];
    println!("{:#?}", Solution::remove_duplicates(&mut vec));
    println!("{:#?}", vec);
}
