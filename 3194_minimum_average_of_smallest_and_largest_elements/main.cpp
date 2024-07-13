////////////////////////////////////////////////////
//                    LeetCode                    //
//       3194. Minimum Average of Smallest        //
//              and Largest Elements              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<double> averages;
        for(int i = 0; i < nums.size() / 2; i++) {
            int minElement, maxElement; 
            minElement = nums[i];
            maxElement = nums[nums.size()-i-1];
            const double avg = (double)(minElement + maxElement) / 2;
            averages.push_back(avg);
        }
        return *min_element(averages.begin(), averages.end());
    }
};