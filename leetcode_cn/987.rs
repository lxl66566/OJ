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
use std::collections::BTreeMap;
use std::rc::Rc;
impl Solution {
    pub fn vertical_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut map: BTreeMap<(i32, i32), Vec<i32>> = BTreeMap::new();
        fn dfs(
            node: &Option<Rc<RefCell<TreeNode>>>,
            x: i32,
            y: i32,
            map: &mut BTreeMap<(i32, i32), Vec<i32>>,
        ) {
            if let Some(node) = node {
                let node = node.borrow();
                map.entry((y, x)).or_default().push(node.val);
                dfs(&node.left, x + 1, y - 1, map);
                dfs(&node.right, x + 1, y + 1, map);
            }
        }
        dfs(&root, 0, 0, &mut map);
        map.values_mut().for_each(|v| v.sort_unstable());
        let mut y = map.keys().next().unwrap().0;
        let mut ans = vec![];
        let mut temp = vec![];
        for (k, v) in map.into_iter() {
            if k.0 != y {
                ans.push(temp);
                temp = vec![];
            }
            y = k.0;
            temp.extend(v);
        }
        if !temp.is_empty() {
            ans.push(temp);
        }
        ans
    }
}

fn main() {
    let root = Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 2,
            left: Some(Rc::new(RefCell::new(TreeNode::new(4)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(5)))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 3,
            left: Some(Rc::new(RefCell::new(TreeNode::new(6)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
        }))),
    }));
    let tree = Some(root);
    println!("{:#?}", Solution::vertical_traversal(tree));
}
