////////////////////////////////////////////////////
//                    LeetCode                    //
//              70. Climbing Stairs               //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 { n } else {
            let (mut a, mut b) = (1, 2);
            for _ in 3..=n {
                let sum = a + b;
                a = b;
                b = sum;
            }
            b
        }
    }
}
