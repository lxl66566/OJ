// use rand::{Rng,thread_rng};
fn main() {
    let mut maxn = 1;
    let a = (1..=26).into_iter().collect::<Vec<i32>>();
    (0..1 << a.len()).for_each(|i|{
        let mut row:Vec<i32> = Vec::new();
        
        a.iter().enumerate().for_each(|(j, num)| {
            if ((i >> j) & 1) != 0 {
                row.push(*num);
            }
        });

        let mut flag = true;
        for &i in row.iter() {
            if row.contains(&(i + 5)) || row.contains(&(i + 8)) { flag = false; break; }
        }
        if flag
        {
            if row.len() > maxn { maxn = row.len(); }
        }
        println!("{}",maxn);
    });
}
