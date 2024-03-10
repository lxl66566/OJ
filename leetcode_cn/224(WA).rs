struct Solution;

#[derive(Debug)]
struct lock_vec {
    pub v: Vec<u8>,
    lock: usize,
}
impl lock_vec {
    pub fn new(v: Vec<u8>) -> Self {
        let l = v.len();
        lock_vec { lock: l, v }
    }
    pub fn last_mut(&mut self) -> Option<&mut u8> {
        if self.v.len() > self.lock {
            self.v.last_mut()
        } else {
            None
        }
    }
    pub fn pop(&mut self) -> Option<u8> {
        if self.v.len() > self.lock {
            self.v.pop()
        } else {
            None
        }
    }
    pub fn push(&mut self, value: u8) {
        self.v.push(value)
    }
    pub fn lock(&mut self) {
        self.lock += 1;
        self.v.resize_with(self.lock, || b'+');
    }
    pub fn unlock(&mut self) {
        self.lock -= 1
    }
}

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut num_stack: Vec<i32> = vec![0];
        let mut op_stack: lock_vec = lock_vec::new(vec![]);
        for i in s.bytes() {
            match i {
                b' ' => continue,
                b'0'..=b'9' => {
                    // dbg!(&i - b'0');
                    let num = (i - b'0') as i32;
                    match op_stack.pop() {
                        Some(b'+') => *num_stack.last_mut().unwrap() += num,
                        Some(b'-') => *num_stack.last_mut().unwrap() -= num,
                        None => {
                            let lastnum = num_stack.last_mut().unwrap();
                            *lastnum = *lastnum * 10 + num;
                        }
                        _ => unreachable!(),
                    }
                }
                b'+' | b'-' => op_stack.push(i),
                b'(' => {
                    op_stack.lock();
                    num_stack.push(0);
                }
                b')' => {
                    op_stack.unlock();
                }
                _ => unreachable!(),
            }
            // dbg!(&num_stack);
        }
        // dbg!(&num_stack, &op_stack);
        op_stack.lock = 0;
        while let Some(op) = op_stack.pop() {
            let n = num_stack.pop().unwrap();
            let temp = &mut 0;
            let last = num_stack.last_mut().unwrap_or(temp);
            match op {
                b'+' => *last += n,
                b'-' => *last -= n,
                _ => unreachable!(),
            }
        }
        num_stack.into_iter().sum()
    }
}
fn main() {
    println!("{:#?}", Solution::calculate("1+1".into()));
    println!("{:#?}", Solution::calculate(" 2-1 + 2 ".into()));
    println!("{:#?}", Solution::calculate("(1+(4+5+2)-3)+(6+8)".into()));
    println!("{:#?}", Solution::calculate("2147483647".into()));
    println!("{:#?}", Solution::calculate("1-(     -2)".into()));
    println!("{:#?}", Solution::calculate("- (3 + (4 + 5))".into()));
    println!("{:#?}", Solution::calculate("1-11".into()));
}
