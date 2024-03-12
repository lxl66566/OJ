struct Solution;
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::ops::Not;
use std::rc::Rc;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut ans = true;
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, ans: &mut bool) -> i32 {
            if node.is_none() || ans.not() {
                return 0;
            }
            let node = node.unwrap();
            let l_dep = dfs(node.borrow().left.clone(), ans);
            let r_dep = dfs(node.borrow().right.clone(), ans);
            if (l_dep - r_dep).abs() > 1 {
                *ans = false;
            }
            l_dep.max(r_dep) + 1
        }
        dfs(root, &mut ans);
        ans
    }
}
fn main() {
    let tree = TreeNode {
        val: 3,
        left: Some(Rc::new(RefCell::new(TreeNode::new(9)))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 20,
            left: Some(Rc::new(RefCell::new(TreeNode::new(15)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
        }))),
    };
    print!(
        "{}",
        Solution::is_balanced(Some(Rc::new(RefCell::new(tree))))
    )
}
