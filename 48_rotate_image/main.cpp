////////////////////////////////////////////////////
//                    LeetCode                    //
//                48. Rotate Image                //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // transpose
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j <= i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // reverse
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size() / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - j - 1];
                matrix[i][matrix.size() - j - 1] = temp;

            }
        }
        
    }
};

void print_matrix(vector<vector<int>>& matrix) {
    for(auto & row : matrix) {
        cout << "[ ";
        for(auto & elem : row) {
            cout << elem << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    
    Solution solution = {};

    vector<vector<int>> m1 {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    print_matrix(m1);
    solution.rotate(m1);
    print_matrix(m1);
 
    vector<vector<int>> m2 {{ 5, 1, 9, 11 },{ 2, 4, 8, 10 },{ 13, 3, 6, 7 },{ 15, 14, 12, 16 }};
    print_matrix(m2);
    solution.rotate(m2);
    print_matrix(m2);

    return EXIT_SUCCESS;
}