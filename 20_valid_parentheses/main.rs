////////////////////////////////////////////////////
//                    LeetCode                    //
//             20. Valid Parentheses              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

macro_rules! is_match {
    ($stack:ident, $par:literal) => {
        if $stack.pop() != Some($par) { 
            return false;
        }
    }
}

pub struct Solution {}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack : Vec<char> = Vec::new();
        for c in s.chars() {
            match c {
                '(' | '[' | '{' => { stack.push(c) }
                ')' => { is_match!(stack, '(') }
                ']' => { is_match!(stack, '[') }
                '}' => { is_match!(stack, '{') }
                _ => { }
            }
        }
        stack.is_empty()
    }
}

fn main() {
    assert_eq!(Solution::is_valid("()".to_string()), true);
    assert_eq!(Solution::is_valid("()[]{}".to_string()), true);
    assert_eq!(Solution::is_valid("(]".to_string()), false);
    println!("Success!");
}