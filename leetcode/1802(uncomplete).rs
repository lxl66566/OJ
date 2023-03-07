struct Solution;
impl Solution {
    pub fn rank(l:i32,r:i32) -> i32{
        (l + r) * (r - l + 1) / 2
    }
    pub fn get_max_sum(n: i32, index: i32, max_num:i32) -> i32
    {
        let mut ans = 0;
        if(max_num > index)
        {
            ans += rank(max_num - index + 1,max_num);
        }
        else{ ans += rank(1,max_num) + index - max_num; }
        if(max_num > n - index + 1)
        {
            ans += rank(max_num - n + index,max_num);
        }
        else{ ans += rank(1,max_num) + (n - index + 1) - max_num; }
        ans
    }
    pub fn max_value(n: i32, index: i32, max_sum: i32) -> i32 {
        
    }
}
fn main()
{
    println!("{}",Solution::max_value(1,3,10));
}