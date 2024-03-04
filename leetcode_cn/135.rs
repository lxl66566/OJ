struct Solution;
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut candy = vec![0; ratings.len()];
        let mut choose_set = ratings
            .iter()
            .enumerate()
            .map(|(i, &x)| (i, x))
            .collect::<Vec<_>>();
        choose_set.sort_by(|a, b| a.1.cmp(&b.1));
        for (i, x) in choose_set.into_iter() {
            if candy[i] != 0 {
                continue;
            }
            let left = i.saturating_sub(1);
            let right = (i + 1).min(ratings.len() - 1);
            for lr in [left, right] {
                if x > ratings[lr] && candy[lr] != 0 {
                    candy[i] = candy[i].max(candy[lr] + 1);
                }
            }
            if candy[i] == 0 {
                candy[i] = 1;
            }
        }
        candy.into_iter().sum()
    }
}

fn main() {
    println!("{:#?}", Solution::candy(vec![1, 2, 3, 2, 0, 1, 3, 6, 4]));
}
