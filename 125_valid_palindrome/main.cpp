////////////////////////////////////////////////////
//                    LeetCode                    //
//             125. Valid Palindrome              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), 
        []( auto const& c ) -> bool { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return tolower(c); });
        string str = s;
        reverse(str.begin(), str.end());
        cout << s << endl;
        cout << str << endl;
        return s == str;
    }
};

int main() {

    Solution solution = {};
    
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    
    return EXIT_SUCCESS;
}