// 求最长的子串，使串内任意两个相邻字符不相同。
fn main() {
    std::io::stdin().read_line(&mut String::new()).unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut ans = 1;
    let mut tmp = 1;
    let s: Vec<_> = s.trim().chars().collect();

    for i in 1..s.len() {
        if s[i] == s[i - 1] {
            ans = ans.max(tmp);
            tmp = 1;
        } else {
            tmp += 1;
        }
        // dbg!(ans, tmp);
    }
    println!("{}", ans.max(tmp));
}
