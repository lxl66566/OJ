struct Solution;
impl Solution {
    pub fn min_max_game(mut nums: Vec<i32>) -> i32 {
        while nums.len() > 1 {
            let mut temp: Vec<i32> = Vec::new();
            let mut temp2 = true;
            for i in (0..nums.len()).step_by(2) {
                if temp2{
                    temp.push(std::cmp::min(nums[i], nums[i + 1]));
                }
                else {temp.push(std::cmp::max(nums[i], nums[i + 1]));}
                temp2 = !temp2;
            }
            nums = temp;
        }
        *nums.first().unwrap()
    }
}
fn main()
{
    println!("{}",Solution::min_max_game(vec![4,3,5,2,4,8,2,2]));
}