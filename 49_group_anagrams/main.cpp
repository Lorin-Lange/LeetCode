////////////////////////////////////////////////////
//                    LeetCode                    //
//               49. Group Anagrams               //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }
        vector<vector<string>> res;
        for(auto p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};

void print_lists(vector<vector<string>>& lists) {
    cout << "[";
    for(int i = 0; i < lists.size(); i++) {
        cout << "[";
        for(int j = 0; j < lists[i].size(); j++) {
            cout << lists[i][j];
            if(j < lists[i].size() - 1) {
                cout << ", ";
            }
        }
        if(i < lists.size() - 1) {
            cout << "], ";
        } else {
            cout << "]";
        }
    }
    cout << "]" << endl;
}

int main() {

    Solution solution = {};
    
    vector<string> str1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
    // [["bat"],["nat","tan"],["ate","eat","tea"]]
    vector<vector<string>> res1 = solution.groupAnagrams(str1);
    print_lists(res1);

    vector<string> str2 = { "" };
    // [[""]]
    vector<vector<string>> res2 = solution.groupAnagrams(str2);
    print_lists(res2);

    vector<string> str3 = { "a" };
    // [["a"]]
    vector<vector<string>> res3 = solution.groupAnagrams(str3);
    print_lists(res3);
    
    return EXIT_SUCCESS;
}