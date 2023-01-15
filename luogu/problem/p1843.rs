use std::collections::BinaryHeap;
use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("failed to read");
    let nab : Vec<i32> = s.trim().split(" ").map(|x| x.parse().unwrap_or(0)).collect();
    let mut w: BinaryHeap<i32> = BinaryHeap::new();
    for _ in 0..nab[0]
    {
        s = String::new();
        io::stdin().read_line(&mut s).expect("failed to read");
        w.push(s.trim().parse().unwrap());
    }
    let mut ans = 0;
    loop
    {
        // let temp = w.pop().unwrap();
        // w.push(temp - nab[2]);
        *w.peek_mut().unwrap() -= nab[2];
        ans += 1;
        if *w.peek().unwrap() <= nab[1] * ans { break; }
    }
    println!("{}",ans);
}
