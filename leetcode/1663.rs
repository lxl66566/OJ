struct Solution;
impl Solution {
    pub fn get_smallest_string(n: i32,mut k: i32) -> String {
        k -= n;
        let mut ans = vec!['a';(n - (k / 25 + if k % 25 > 0 { 1 } else { 0 })) as usize].into_iter().collect::<String>();
        if k % 25 != 0 {ans.push(('a' as i32 + k % 25) as u8 as char);}
        ans.push_str(vec!['z';(k / 25) as usize].into_iter().collect::<String>().as_str());
        ans
    }
}

fn main() {
    println!("{}",Solution::get_smallest_string(24, 552));
}
