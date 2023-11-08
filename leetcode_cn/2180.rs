struct Solution;
impl Solution {
    pub fn count_even(num: i32) -> i32 {
        num / 1000 * 500 + count_even_hundred(num % 1000, num / 1000 % 2 == 1)
    }
}
fn count_even_hundred(num: i32, mut even: bool) -> i32 {
    if num / 100 % 2 == 1 {even = !even;}
    num / 100 * 50 + count_even_ten(num % 100, even)
}
fn count_even_ten(num: i32, mut even: bool) -> i32 {
    let mut ans = num / 10 * 5 - 1;
    if num / 10 % 2 == 1 {even = !even;}
    ans += if even { (num % 10 + 1) / 2 } else { num % 10 / 2 + 1 };
    ans
}
fn main()
{
    println!("{}",Solution::count_even(1000));
}