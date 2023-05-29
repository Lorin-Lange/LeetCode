////////////////////////////////////////////////////
//                    LeetCode                    //
//             461. Hamming Distance              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int bitmask = x ^ y;
        int counter = 1;
        while (counter < 32) {
            result += bitmask & 1;
            bitmask = bitmask >> 1;
            counter++;
        }
        return result;
    }
};

int main() {
    Solution solution = {};
    cout << solution.hammingDistance(1, 4) << endl;
    
    return EXIT_SUCCESS;
}