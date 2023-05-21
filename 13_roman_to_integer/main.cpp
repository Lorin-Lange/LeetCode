////////////////////////////////////////////////////
//                    LeetCode                    //
//              13. Roman to Integer              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int j = get_int(s[i]);
            if(j < get_int(s[i+1])) {
                ans -= j;
            } else {
                ans += j;
            }
        }
        return ans;
    }

private:
    int get_int(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
};

int main() {

    Solution solution = {};
    string s = "MCMXCIV";
    cout << solution.romanToInt(s) << endl;

    return EXIT_SUCCESS;   
}