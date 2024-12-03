//! 一面：rust 写快排

fn sort(a: &mut [i64]) {
    if a.len() <= 1 {
        return;
    }
    let standard = *a.first().unwrap();
    let mut i = 0;
    let mut j = a.len() - 1;
    while i < j {
        while a[i] <= standard && i < j {
            i += 1;
        }
        while a[j] >= standard && i < j {
            j -= 1;
        }
        if a[i] > a[j] {
            a.swap(i, j);
        }
    }
    assert_eq!(i, j);
    if a[i] < a[0] {
        a.swap(0, i);
    }
    // dbg!(i);
    // dbg!(&a);
    sort(&mut a[..i]);
    sort(&mut a[j..]);
}

fn main() {
    let a = vec![
        vec![1, 5, 6, 3, 4, 2],
        vec![6, 1, 5, 3, 2, 0],
        vec![2, 2, 3, -3, 5, -5],
        vec![1],
        vec![1, 1, 1],
        vec![2, 1],
        vec![1, 2, 3],
    ];
    for mut i in a {
        sort(&mut i);
        dbg!(i);
    }
}
