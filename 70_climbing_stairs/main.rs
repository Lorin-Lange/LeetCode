////////////////////////////////////////////////////
//                    LeetCode                    //
//              70. Climbing Stairs               //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

struct Solution;

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

fn main() {
    println!("70. Climbing Stairs");
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn case_1() {
        assert_eq!(Solution::climb_stairs(2), 2);
    }

    #[test]
    fn case_2() {
        assert_eq!(Solution::climb_stairs(3), 3);
    }

    #[test]
    fn case_3() {
        assert_eq!(Solution::climb_stairs(5), 8);
    }

    #[test]
    fn case_4() {
        assert_eq!(Solution::climb_stairs(27), 317811);
    }

    #[test]
    fn case_5() {
        assert_eq!(Solution::climb_stairs(45), 1836311903);
    }

}
