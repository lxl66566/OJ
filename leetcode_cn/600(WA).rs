struct Solution;
impl Solution {
    pub fn find_integers(mut n: i32) -> i32 {
        let mut dp = vec![2, 3];
        let mut ans = 1;
        let mut i = 0;
        while 1 << i <= n {
            let s = dp
                .iter()
                .enumerate()
                .filter(|(index, &_x)| index % 2 != i % 2)
                .map(|(_, &x)| x)
                .sum::<i32>();
            dp.push(s);
            i += 1;
        }
        dbg!(&dp);
        let mut mark = false;
        loop {
            if n & (1 << (i)) != 0 {
                if !mark {
                    ans += dp[i] - 1;
                    dbg!(i);
                    mark = true;
                } else {
                    mark = false;
                    if i > 0 {
                        n |= 1 << (i - 1);
                    }
                }
            } else {
                mark = false;
            }
            let res = i.overflowing_sub(1);
            if res.1 {
                break;
            } else {
                i = res.0;
            }
        }
        ans
    }
}

fn main() {
    println!("{}", Solution::find_integers(5)); // 4
    println!("{}", Solution::find_integers(8)); // 5
    println!("{}", Solution::find_integers(26)); // 13
                                                 // 0
                                                 // 1
                                                 // 10
                                                 // 100
                                                 // 101
                                                 // 1000
                                                 // 1001
                                                 // 1010
                                                 // 10000
                                                 // 10001
                                                 // 10010
                                                 // 10100
                                                 // 10101
}
