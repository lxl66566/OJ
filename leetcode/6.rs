struct Solution;
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 { return s; }
        let mut v: Vec<Vec<char>> = vec![Vec::new();num_rows as usize];
        dbg!(v.len());
        let mut forward = true;
        let mut i: i32 = 0;
        for c in s.chars().into_iter() {
            dbg!(i);
            v[i as usize].push(c);
            i += if forward { 1 } else { -1 };
            if i >= num_rows - 1 || i <= 0 { forward = !forward; }
        }
        let mut ans = String::new();
        for i in v {
            ans.push_str(i.iter().collect::<String>().as_str());
        }
        ans
    }
}
fn main() {
    println!("{}",Solution::convert(String::from("PAYPALISHIRING"), 3));
}
