struct Solution;
impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        x.powi(n)
    }
}

fn main() {
    println!("{}",Solution::my_pow(2f64,-2));
}
