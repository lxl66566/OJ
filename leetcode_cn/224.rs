use std::cell::RefCell;

struct Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        Self::calculate_u8(s.into_bytes())
    }
    pub fn calculate_u8(s: Vec<u8>) -> i32 {
        let mut num_stack: Vec<i32> = vec![];
        let mut current_num = None;
        let op_rec = RefCell::new(None);
        let mut sub = 0;
        let mut sub_tmp_str = vec![];

        fn push_num(num: i32, num_stack: &mut Vec<i32>, op_rec: &RefCell<Option<u8>>) {
            match op_rec.borrow_mut().take() {
                Some(b'+') => {
                    if let Some(n) = num_stack.last_mut() {
                        *n += num;
                    } else {
                        num_stack.push(num);
                    }
                }
                Some(b'-') => {
                    if let Some(n) = num_stack.last_mut() {
                        *n -= num;
                    } else {
                        num_stack.push(-num);
                    }
                }
                None => {
                    num_stack.push(num);
                }
                _ => unreachable!(),
            }
        }

        for i in s {
            //dbg!(i as char);
            match i {
                b' ' => {
                    if sub != 0 {
                        sub_tmp_str.push(i);
                        continue;
                    }
                    if let Some(num) = current_num {
                        push_num(num, &mut num_stack, &op_rec);
                        current_num = None;
                    }
                }
                b'0'..=b'9' => {
                    if sub != 0 {
                        sub_tmp_str.push(i);
                        continue;
                    }
                    let one_num = (i - b'0') as i32;
                    if let Some(num) = current_num.as_mut() {
                        *num *= 10;
                        *num += one_num;
                    } else {
                        current_num = Some(one_num);
                    }
                }
                b'+' | b'-' => {
                    if sub != 0 {
                        sub_tmp_str.push(i);
                        continue;
                    }
                    if let Some(num) = current_num {
                        push_num(num, &mut num_stack, &op_rec);
                        current_num = None;
                    }
                    op_rec.borrow_mut().replace(i);
                }
                b'(' => {
                    if sub != 0 {
                        sub_tmp_str.push(i);
                    }
                    sub += 1;
                }
                b')' => {
                    sub -= 1;
                    if sub == 0 {
                        let mut input = vec![];
                        std::mem::swap(&mut sub_tmp_str, &mut input);
                        //dbg!(String::from_utf8(input.clone()).unwrap());
                        let res = Self::calculate_u8(input);
                        //dbg!(&res);
                        push_num(res, &mut num_stack, &op_rec);
                    } else {
                        sub_tmp_str.push(i);
                        continue;
                    }
                }
                _ => unreachable!(),
            }
            // //dbg!(
            //     &num_stack,
            //     &current_num,
            //     &op_rec,
            //     &sub,
            //     String::from_utf8(sub_tmp_str.clone()).unwrap()
            // );
        }
        if let Some(num) = current_num {
            push_num(num, &mut num_stack, &op_rec);
        }
        // //dbg!(
        //     &num_stack,
        //     &current_num,
        //     &op_rec,
        //     &sub,
        //     String::from_utf8(sub_tmp_str.clone()).unwrap()
        // );
        num_stack.into_iter().sum()
    }
}

fn main() {
    println!("{:#?}", Solution::calculate("1+1".into()));
    println!("{:#?}", Solution::calculate(" 2-1 + 2 ".into()));
    println!("{:#?}", Solution::calculate("(1+(4+5+2)-3)+(6+8)".into())); //23

    println!("{:#?}", Solution::calculate("2147483647".into()));
    println!("{:#?}", Solution::calculate("1-(     -2)".into()));
    println!("{:#?}", Solution::calculate("- (3 + (4 + 5))".into()));
    println!("{:#?}", Solution::calculate("1-11".into()));
}
