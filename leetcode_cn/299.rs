struct Solution;
impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        let mut guess_heap = [0; 10];
        let mut secret_heap = guess_heap.clone();
        let mut same_heap = [0; 10];
        for i in 0..secret.len() {
            let guess_number = guess.as_bytes()[i] - b'0';
            let secret_number = secret.as_bytes()[i] - b'0';
            guess_heap[guess_number as usize] += 1;
            secret_heap[secret_number as usize] += 1;
            if secret_number == guess_number {
                same_heap[guess_number as usize] += 1;
            }
        }
        let b = guess_heap
            .into_iter()
            .enumerate()
            .map(|(i, num)| num.min(secret_heap[i]) - same_heap[i])
            .sum::<i32>();
        format!("{}A{}B", same_heap.into_iter().sum::<i32>(), b)
    }
}

fn main() {
    println!("{:#?}", Solution::get_hint("1807".into(), "7810".into()));
    println!("{:#?}", Solution::get_hint("1123".into(), "0111".into()));
}
