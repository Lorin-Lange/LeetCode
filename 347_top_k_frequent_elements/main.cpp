////////////////////////////////////////////////////
//                    LeetCode                    //
//          347. Top K Frequent Elements          //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num] += 1;
        }
        vector<pair<int, int>> mvec;
        for (auto& it : m) {
            mvec.push_back(it);
        }
        sort(mvec.begin(), mvec.end(), 
        [](pair<int, int>& a, pair<int, int>& b) { 
            return a.second > b.second; 
        });
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(mvec[i].first);
        }
        return res;
    }
};

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

int main() {
    
    Solution solution = {};

    vector<int> vec0 = { 1, 1, 1, 2, 2, 3 };
    print_vector(solution.topKFrequent(vec0, 2));

    vector<int> vec1 = { 1 };
    print_vector(solution.topKFrequent(vec1, 1));

    vector<int> vec2 = { 4,1,-1,2,-1,2,3 };
    print_vector(solution.topKFrequent(vec2, 2));

    return EXIT_SUCCESS;
}