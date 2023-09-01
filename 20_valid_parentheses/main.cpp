////////////////////////////////////////////////////
//                    LeetCode                    //
//             20. Valid Parentheses              //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            switch(c) {
                case '(': st.push(c);
                          break;
                case ')': if(!st.empty() && st.top() == '(') {
                            st.pop();
                          } else {
                            return false;
                          }
                          break;
                case '[': st.push(c);
                          break;
                case ']': if(!st.empty() && st.top() == '[') {
                            st.pop();
                          } else {
                            return false;
                          }
                          break;
                case '{': st.push(c);
                          break;
                case '}': if(!st.empty() && st.top() == '{') {
                            st.pop();
                          } else {
                            return false;
                          }
                          break;
                default: break;
            }
        }
        return st.empty();
    }
};

int main() {
  Solution solution = {};
  cout << solution.isValid("((()))") << endl;
  
  return EXIT_SUCCESS;
}