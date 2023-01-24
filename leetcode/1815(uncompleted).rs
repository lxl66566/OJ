struct Solution;
impl Solution {
    pub fn max_happy_groups(batch_size: i32, mut groups: Vec<i32>) -> i32 {
        let mut batch = vec![0;10];
        assert!(batch_size < 10);
        groups.iter_mut().for_each(|x| {*x %= batch_size;batch[*x as usize] += 1;});
        let mut ans = batch[0];
        for i in 1..(batch_size + 1) / 2 {
            if batch[i as usize] == 0 { continue; }
            let temp = i32::min(batch[i as usize], batch[(batch_size - i) as usize]);
            ans += temp;
            batch[i as usize] -= temp;batch[(batch_size - i) as usize] -= temp;
        }
        if batch_size % 2 == 0 {
            ans += batch[(batch_size / 2) as usize] / 2;
            batch[(batch_size / 2) as usize] %= 2;
        }
        dbg!(batch);

        ans
    }
}

fn main() {
    println!("{}",Solution::max_happy_groups(4, vec![1,3,2,5,2,2,1,6]));
}
