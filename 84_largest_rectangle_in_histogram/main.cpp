////////////////////////////////////////////////////
//                    LeetCode                    //
//       84. Largest Rectangle in Histogram       //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // fails at 90 / 99 testcases passed
    // too slow: Time Limit Exceeded
    int _largestRectangleArea(vector<int>& heights) {
        int current_max = -1;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] > current_max) current_max = heights[i];
            int min = heights[i];
            for(int j = i; j < heights.size(); j++) {
                if(heights[j] < min) min = heights[j];
                int local_max = (j - i + 1) * min;
                if(current_max < local_max) current_max = local_max;
            }
        }
        return current_max;
    }
};


int main() {

    vector<int> case1 = {2, 1, 5, 6, 2, 3};
    vector<int> case2 = {2, 4};
    Solution solution;
    cout << "Case 1: " << solution._largestRectangleArea(case1) << endl;
    cout << "Case 2: " << solution._largestRectangleArea(case2) << endl;

    return EXIT_SUCCESS;
}