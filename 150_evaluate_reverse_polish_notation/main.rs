////////////////////////////////////////////////////
//                    LeetCode                    //
//     150. Evaluate Reverse Polish Notation      //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

pub struct Solution {}

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack : Vec<i32> = Vec::new();
        for token in tokens {
            match token.as_str() {
                "+" => {
                    let v1 = stack.pop().unwrap();
                    let v2 = stack.pop().unwrap();
                    stack.push(v2 + v1);
                }
                "-" => {
                    let v1 = stack.pop().unwrap();
                    let v2 = stack.pop().unwrap();
                    stack.push(v2 - v1);
                }
                "*" => {
                    let v1 = stack.pop().unwrap();
                    let v2 = stack.pop().unwrap();
                    stack.push(v2 * v1);
                }
                "/" => {
                    let v1 = stack.pop().unwrap();
                    let v2 = stack.pop().unwrap();
                    stack.push(v2 / v1);
                }
                _ => { stack.push(token.parse().unwrap()) }
            }
        }
        stack.pop().unwrap()
    }
}

fn main() {

    let v1: Vec<String> = ["2","1","+","3","*"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::eval_rpn(v1), 9);

    let v2: Vec<String> = ["4","13","5","/","+"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::eval_rpn(v2), 6);

    let v3: Vec<String> = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::eval_rpn(v3), 22);

    println!("Success!");
}