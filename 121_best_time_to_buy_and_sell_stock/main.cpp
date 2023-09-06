////////////////////////////////////////////////////
//                    LeetCode                    //
//      121. Best Time to Buy and Sell Stock      //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min = 10000;
        int profit = 0;
        for (int price : prices) {
            if(max < price) {
                max = price;
            }
            if(min > price) {
                min = price;
                max = 0;
            }
            int delta = max - min;
            if(delta > profit) {
                profit = delta;
            }
        }
        return profit;
    }
};

int main() {
    
    Solution solution = {};
    vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    cout << solution.maxProfit(vec) << endl;

    return EXIT_SUCCESS;
}