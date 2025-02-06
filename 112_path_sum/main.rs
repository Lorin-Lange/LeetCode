////////////////////////////////////////////////////
//                    LeetCode                    //
//                 112. Path Sum                  //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

use std::rc::Rc;
use std::cell::RefCell;

struct Solution;

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

impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        match root {
            None => false,
            Some(node) => {
                let mut node = node.borrow_mut();
                let sum = target_sum - node.val;
                if node.left.is_none() && node.right.is_none() { 
                    return sum == 0 
                }
                   Self::has_path_sum(node.left.take(), sum) 
                || Self::has_path_sum(node.right.take(), sum)
            }
        }
    }
}

fn main() {
    let _ = Solution::has_path_sum(None, 0);
    println!("112. Path Sum");
}
