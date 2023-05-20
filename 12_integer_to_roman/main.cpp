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
        string str1 = digitsToRoman(mod);
        m -= mod;
        mod = m % 100;
        string str10 = tensToRoman(mod);
        m -= mod;
        mod = m % 1000;
        string str100 = hundredsToRoman(mod);
        m -= mod;
        mod = m % 10000;
        string str1000 = thousandsToRoman(mod);
        return str1000 + str100 + str10 + str1;
    }

private:
    string digitsToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 4: return "IV";
            case 5: return "V";
            case 9: return "IX";
            default: return digitsToRoman(i - 1) + "I";
        }
    }
    
    string tensToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 40: return "XL";
            case 50: return "L";
            case 90: return "XC";
            default: return tensToRoman(i - 10) + "X";
        }
    }

    string hundredsToRoman(int i) {
        switch(i) {
            case 0: return "";
            case 400: return "CD";
            case 500: return "D";
            case 900: return "CM";
            default: return hundredsToRoman(i - 100) + "C";
        }
    }

    string thousandsToRoman(int i) {
        if (i == 0) {
            return "";
        } else {
            return thousandsToRoman(i - 1000) + "M";
        }
    }
};

int main() {
    Solution solution = {};
    cout << solution.intToRoman(1994) << endl;

    return EXIT_SUCCESS;
}