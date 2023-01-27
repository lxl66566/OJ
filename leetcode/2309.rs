struct Solution;
impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut m = vec![vec![0,0];26];
        s.chars().for_each(|x| {
            if x.is_lowercase() { m[x as usize - 'a' as usize][0] += 1; }
            else { m[x as usize - 'A' as usize][1] += 1; }
        });
        for (j,i) in m.iter().rev().enumerate() {
            if i[0] > 0 && i[1] > 0 {return String::from((25_u8 - j as u8 + 'A' as u8) as char)}
        }
        String::from("")
    }
}

fn main() {
    println!("{}",Solution::greatest_letter(String::from("lEeTcOdE")));
}
