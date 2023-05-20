////////////////////////////////////////////////////
//                    LeetCode                    //
//              12. Integer to Roman              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int m = num;
        int mod = m % 10;
        string str10 = decimalsToRoman(mod);
        m -= mod;
        mod = m % 100;
        string str100 = dToRoman(mod);
        m -= mod;
        mod = m % 1000;
        string str1000 = mToRoman(mod);
        m -= mod;
        mod = m % 10000;
        string str10000 = mmToRoman(mod);
        return str10000 + str1000 + str100 + str10;
    }

private:
    string decimalsToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 4: return "IV";
            case 5: return "V";
            case 9: return "IX";
            default: return decimalsToRoman(i - 1) + "I";
        }
    }
    
    string dToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 40: return "XL";
            case 50: return "L";
            case 90: return "XC";
            default: return dToRoman(i - 10) + "X";
        }
    }

    string mToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 400: return "CD";
            case 500: return "D";
            case 900: return "CM";
            default: return mToRoman(i - 100) + "C";
        }
    }

    string mmToRoman(int i) {
        if (i == 0) {
            return "";
        } else {
            return mmToRoman(i - 1000) + "M";
        }
    }
};

int main() {
    Solution solution = {};
    cout << solution.intToRoman(1994) << endl;

    return EXIT_SUCCESS;
}