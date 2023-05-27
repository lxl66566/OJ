use std::collections::HashMap;

fn count_elements(vec: &[i32]) -> HashMap<i32, usize> {
    vec.iter().fold(HashMap::new(), |mut acc, &x| {
        *acc.entry(x).or_insert(0) += 1
    })
}

fn main() {
    let vec = vec![1, 2, 2, 3, 3, 3];
    let counts = count_elements(&vec);
    println!("{:?}", counts);
}
