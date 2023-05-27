use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("failed to read");
    let nx0 : Vec<i128> = s.trim().split(" ").map(|x| x.parse().unwrap_or(0)).collect();
    s = String::new();
    io::stdin().read_line(&mut s).expect("failed to read");
    let a : Vec<i128> = s.trim().split(" ").map(|x| x.parse().unwrap_or(0)).collect();
    s = String::new();
    io::stdin().read_line(&mut s).expect("failed to read");
    let b : Vec<i128> = s.trim().split(" ").map(|x| x.parse().unwrap_or(0)).collect();
    let mut mant:i128 = *nx0.last().unwrap();
    let mut ans = 0i128;

    // println!("{:?}",a);
    for (i,x) in a.iter().enumerate() {
        if *x <= mant {
            mant += b[i];
            ans += 1;
        }
    }
    println!("{ans}");
}