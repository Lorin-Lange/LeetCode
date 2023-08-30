////////////////////////////////////////////////////
//                    LeetCode                    //
//       238. Product of Array Except Self        //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        if(i < vec.size() - 1) {
            cout << vec[i] << ", ";
        } else {
            cout << vec[i];
        }
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec = nums;
        int product = 1;
        for(int i = 0; i < nums.size(); i++) {
            vec[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            vec[i] *= product;
            product *= nums[i];
        }
        return vec;
    }
};


int main() {

    Solution solution = {};

    vector<int> vec0 = { 1, 2, 3, 4 };
    // [24,12,8,6]
    print_vector(solution.productExceptSelf(vec0));

    vector<int> vec1 = { -1, 1, 0, -3, 3 };
    // [0,0,9,0,0]
    print_vector(solution.productExceptSelf(vec1));

    return EXIT_SUCCESS;
}