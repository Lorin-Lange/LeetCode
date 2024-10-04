////////////////////////////////////////////////////
//                    LeetCode                    //
//       128. Longest Consecutive Sequence        //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int counter = 0;
        int old_counter = 0;
        int last;
        if(nums.size() != 0) last = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - last == 0 && i > 0) continue;
            if(nums[i] - last == 1) {
                counter++;
                last = nums[i];
            } else {
                if(counter > old_counter) old_counter = counter;
                counter = 1;
                last = nums[i];
            }
        }
        if(counter > old_counter) old_counter = counter;
        return old_counter;
    }
};

int main() {

    Solution solution = {};

    vector<int> vec0 = { 100, 4, 200, 1, 3, 2 };
    cout << "Case 1: " << solution.longestConsecutive(vec0) << endl;

    vector<int> vec1 = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    cout << "Case 2: " << solution.longestConsecutive(vec1) << endl;

    return EXIT_SUCCESS;
}