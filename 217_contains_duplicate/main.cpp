////////////////////////////////////////////////////
//                    LeetCode                    //
//            217. Contains Duplicate             //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, bool> map;
		for (auto & num : nums) {
			if (map.find(num) == map.end()) {
				map[num] = false;
			} else {
				return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int> n =  { 1,1,1,3,3,4,3,2,4,2 };
	Solution solution = {};
	cout << solution.containsDuplicate(n) << endl;
	
	return EXIT_SUCCESS;
}