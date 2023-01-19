// struct Solution;
use std::io;
const MOD: i128 = 998_244_353_i128;
fn mod_(x: i128) -> i128
{
    let temp = x % MOD;
    if temp < 0 { temp + MOD } else { temp }
}
fn qpow(mut x: i128,mut y: i128) -> i128
{
    let mut ans = 1_i128;
    while y > 0 {
        if y & 1 == 1 {
            ans = mod_(ans * x);
        }
        x = mod_(x * x);
        y >>= 1;
    }
    ans
}
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("failed to read");
    let t: i32 = s.trim().parse().unwrap();
    for _ in 0..t {
        s = String::new();
        io::stdin().read_line(&mut s).expect("failed to read");
        let input: Vec<i128> = s.trim().split(" ").map(|x| x.parse().unwrap()).collect();
        let mut x: Vec<i128> = vec![input[1],input[2]];let mut y: Vec<i128> = vec![input[3],input[4]];
        x.resize(1000, 0);y.resize(1000, 0);
        let mut ans: i128 = 1;
        if input[0] == 1 {
            ans = mod_(y[0] - x[0]);
            println!("{}", ans);
            continue;
        }
        for i in 0..2 {
            ans *= y[i] - x[i];
        }
        ans = mod_(ans);
        let mut rec = 0;
        for i in 2usize..input[0] as usize
        {
            x[i] = f64::sqrt((x[i-1] * x[i-2]) as f64) as i128 + 1i128;
            y[i] = f64::sqrt((y[i-1] * y[i-2]) as f64) as i128 + 1i128;
            ans = mod_(ans * (y[i] - x[i]));
            // dbg!(x[i]);
            // dbg!(y[i]);
            if (x[i] - x[i-1] == 0 || x[i] - x[i-1] == 1 ) && (y[i] - y[i-1] == 0 || y[i] - y[i-1] == 1 ) 
             && (input[0] as usize - i - 1) % 2 == 0 { rec = i;break; }
        }
        if rec == 0 { println!("{}", ans);continue; }
        if (x[rec - 1] == x[rec - 2] && y[rec - 1] == y[rec - 2]) || (x[rec - 1] == x[rec - 2] + 1 && y[rec - 1] == y[rec - 2] + 1)
        {
            ans = mod_(ans * qpow(y[rec - 1] - x[rec - 1],input[0] - rec as i128 - 1));
        }
        else 
        {
            ans = mod_(ans * qpow((y[rec - 1] - x[rec - 1]) * (y[rec - 2] - x[rec - 2]),(input[0] - rec as i128 - 1) >> 1 ));
        }
        println!("{}",ans);
    }
}
