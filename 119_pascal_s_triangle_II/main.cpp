////////////////////////////////////////////////////
//                    LeetCode                    //
//           119. Pascal's Triangle II            //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex + 1).back();
    }

private:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v = {{1}};
        if(numRows >= 2) {
            v.push_back({1,1});
        }
        for(int i = 1; i < numRows - 1; i++) {
            vector<int> vh = v[i];
            vector<int> newVec;
            newVec.push_back(vh.front());
            for(int j = 0; j < vh.size() - 1; j++) {
                newVec.push_back(vh[j] + vh[j+1]);
            }
            newVec.push_back(vh.back());
            v.push_back(newVec);
        }
        return v;
    }
};

void print_vector(vector<int> v) {
    cout << "[";
    for(auto & e : v) {
        cout << e << ", ";
    }
    cout << "]" << endl;
}

int main() {

    Solution solution = {};

    vector<int> v1 = solution.getRow(0);
    print_vector(v1);

    vector<int> v2 = solution.getRow(3);
    print_vector(v2);

    return EXIT_SUCCESS;
}