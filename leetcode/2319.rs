struct Solution;
impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        let mut flag = true;
        for i in 0..n {
            for j in 0..n {
                if i == j || i + j == n - 1
                {
                    if grid[i][j] == 0 {
                        flag = false;
                        break;
                    }
                }
                else {
                    if grid[i][j] != 0 {
                        flag = false;
                        break;
                    }
                }
            }
            if !flag { break; }
        }
        flag
    }
}
fn main() {
    println!("{}",Solution::check_x_matrix(vec![vec![5,0,0,1],vec![0,4,1,5],vec![0,5,2,0],vec![4,1,0,2]]));
}
