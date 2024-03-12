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
use std::rc::Rc;
impl Solution {
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>) -> u32 {
            if node.is_none() {
                return 0;
            }
            let node = node.unwrap();
            let mut ans: u32 = node.borrow().val as u32;
            let left_val = dfs(node.borrow().left.clone());
            if left_val == 0 {
                node.borrow_mut().left = None;
            } else {
                ans += left_val;
            }
            let right_val = dfs(node.borrow().right.clone());
            if right_val == 0 {
                node.borrow_mut().right = None;
            } else {
                ans += right_val;
            }
            ans
        }
        let val = dfs(root.clone());
        if val == 0 {
            None
        } else {
            root
        }
    }
}
fn main() {
    let tree = Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 0,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
    }));
    Solution::prune_tree(Some(tree.clone()));
    dbg!(tree);
}
