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
    pub fn replace_value_in_tree(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut ans = vec![];

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, calc: &mut Vec<i32>) {
            if node.is_none() {
                return;
            }
            let raw_node = node.unwrap();
            if depth >= calc.len() {
                calc.resize(depth + 1, 0);
            }
            calc[depth] += raw_node.borrow().val;

            let left = raw_node.borrow().left.clone();
            let right = raw_node.borrow().right.clone();

            raw_node.borrow_mut().val = 0;
            if let Some(n) = left.clone() {
                raw_node.borrow_mut().val += n.borrow().val;
            }
            if let Some(n) = right.clone() {
                raw_node.borrow_mut().val += n.borrow().val;
            }
            dfs(left, depth + 1, calc);
            dfs(right, depth + 1, calc);
        }
        dfs(root.clone(), 0, &mut ans);

        fn dfs2(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, calc: &Vec<i32>, fa_value: i32) {
            if node.is_none() {
                return;
            }
            let raw_node = node.unwrap();
            let mut raw_node_bor = raw_node.borrow_mut();
            let my_val = raw_node_bor.val;
            raw_node_bor.val = calc[depth] - fa_value;
            dfs2(raw_node_bor.left.clone(), depth + 1, calc, my_val);
            dfs2(raw_node_bor.right.clone(), depth + 1, calc, my_val);
        }
        let root_val = root.clone().unwrap().borrow().val;
        dfs2(root.clone(), 0, &ans, root_val);
        root.as_ref().unwrap().borrow_mut().val = 0;
        root
    }
}
fn main() {
    let tree = TreeNode {
        val: 5,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 4,
            left: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(10)))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 9,
            left: None,
            right: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
        }))),
    };
    let tree = Solution::replace_value_in_tree(Some(Rc::new(RefCell::new(tree))));
    dbg!(tree);
}
