////////////////////////////////////////////////////
//                    LeetCode                    //
//      121. Best Time to Buy and Sell Stock      //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max = 0;
        let mut min = 10000;
        let mut profit = 0;
        for price in prices {
            if max < price {
                max = price;
            }
            if min > price {
                min = price;
                max = 0;
            }
            let delta = max - min;
            if delta > profit {
                profit = delta;
            }
        }
        profit
    }
}

fn main() {
    println!("121. Best Time to Buy and Sell Stock");
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn case_1() {
        let v1 = vec![7,1,5,3,6,4];
        assert_eq!(Solution::max_profit(v1), 5);
    }

    #[test]
    fn case_2() {
        let v2 = vec![7,6,4,3,1];
        assert_eq!(Solution::max_profit(v2), 0);
    }

}
