////////////////////////////////////////////////////
//                    LeetCode                    //
//                 67. Add Binary                 //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "0") return b;
        if(b == "0") return a;
        if(a.size() != b.size()) {
            int diff = a.size() - b.size();
            int delta = abs(diff);
            if(diff < 0) {
                // a is smaller than b
                for(int i = 0; i < delta; i++) {
                    a = "0" + a;
                }
            } else {
                // b is smaller than a
                for(int i = 0; i < delta; i++) {
                    b = "0" + b;
                }
            }
        }

        a = "0" + a;
        b = "0" + b;

        string res = "";
        bool borrow = false;
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == '1' && b[i] == '1') {
                if(borrow) {
                    res = "1" + res;
                } else {
                    res = "0" + res;
                    borrow = true;
                }
            } else if (a[i] == '0' && b[i] == '0') {
                if(borrow) {
                    res = "1" + res;
                    borrow = false;
                } else {
                    res = "0" + res;
                }
            } else {
                if(borrow) {
                    res = "0" + res;
                } else {
                    res = "1" + res;
                }
            }
        }
        while(res[0] == '0') {
            res.erase(0, 1);
        }
        return res;
    }
};

int main() {

    Solution solution = {};

    string a1 = "11";
    string b1 = "1";
    string res1 = "100";
    cout << solution.addBinary(a1, b1) << endl;

    string a2 = "1010";
    string b2 = "1011";
    string res2 = "10101";
    cout << solution.addBinary(a2, b2) << endl;

    return EXIT_SUCCESS;
}