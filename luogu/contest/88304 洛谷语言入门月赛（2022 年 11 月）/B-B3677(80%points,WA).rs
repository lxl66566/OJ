use std::io;
fn main() {
    let mut s = String::new();
    
    io::stdin().read_line(&mut s).expect("failed to read");
    let num : Vec<i128> = s.trim().split(" ").map(|x| x.parse().unwrap_or(0)).collect();
    if num.last().unwrap() == &0
    {
        println!("NO\nYES");
        return;
    }
    if num.first().unwrap() >= &0
    {
        println!("NO");
    }
    else {
        if (num.last().unwrap()) % 2 == 0 {println!("NO");}
        else {println!("YES");}
    }
    if num.first().unwrap() % 2 == 0 
    {
        println!("NO");
    }
    else {
        if num.last().unwrap()  % 2 == 0 {println!("NO");}
        else {println!("YES");}
    }

}