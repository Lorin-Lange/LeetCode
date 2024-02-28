////////////////////////////////////////////////////
//                    LeetCode                    //
//                   1. Two Sum                   //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (target == nums[i] + nums[j]) {
                    vec.push_back(i);
                    vec.push_back(j);
                    return vec;
                }
            }
        }
        return vec;
    }
};

int main() {
    cout << "Example!" << endl;
    
    return EXIT_SUCCESS;
}