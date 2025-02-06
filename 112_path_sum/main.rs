////////////////////////////////////////////////////
//                    LeetCode                    //
//                 112. Path Sum                  //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>
}

impl TreeNode {#[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        if root.is_none() { return false }
        let root = root.unwrap();
        let mut root = root.borrow_mut();
        let sum = target_sum - root.val;
        if sum == 0 && root.left.is_none() && root.right.is_none() { return true }
        Self::has_path_sum(root.left.take(), sum) || Self::has_path_sum(root.right.take(), sum)
    }
}
