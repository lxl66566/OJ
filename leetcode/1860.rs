struct Solution;
impl Solution {
    pub fn mem_leak(mut memory1: i32, mut memory2: i32) -> Vec<i32> {
        let mut time = 1;
        loop {
            let t = memory1.max(memory2);
            if t < time { break; }
            if memory1 == t { memory1 -= time; }
            else { memory2 -= time; }
            time += 1;
        }
        vec![time,memory1,memory2]
    }
}
fn main() {
    println!("{:#?}",Solution::mem_leak(8,11));
}
