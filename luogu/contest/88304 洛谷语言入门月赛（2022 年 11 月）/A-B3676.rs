use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).ok().expect("failed to read");
    let num: i32 = s.trim().parse().unwrap();
    if num > 2{
        println!("Survivor");
    }
    else if num == 2 {
        println!("Tie");
    }
    else{ println!("Hunter")}
}