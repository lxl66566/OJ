struct Solution;
impl Solution {
    pub fn convert_to_title(mut column_number: i32) -> String {
        let mut result = String::new();
        column_number -= 1;
        while column_number > -1 {
            let remainder = column_number % 26;
            column_number = column_number / 26 - 1;
            result.push((remainder as u8 + b'A') as char);
        }
        result.chars().rev().collect()
    }
}
fn main() {
    println!("{:#?}", Solution::convert_to_title(2147483647));
}
