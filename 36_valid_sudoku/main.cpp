////////////////////////////////////////////////////
//                    LeetCode                    //
//                36. Valid Sudoku                //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check columns and rows
        for(int i = 0; i < 9; i++) {
            set<char> s1;
            set<char> s2;
            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {
                    if(s1.count(board[i][j]) == 1) return false;
                    s1.insert(board[i][j]);
                }

                if(board[j][i] != '.') {
                    if(s2.count(board[j][i]) == 1) return false;
                    s2.insert(board[j][i]);
                }

            }
        }

        // check squares
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                set<char> s;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        char c = board[i + x * 3][j + y * 3];
                        if(c != '.') {
                            if(s.count(c) == 1) return false;
                            s.insert(c);
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    
    Solution solution = {};

    vector<vector<char>> sudoku = 
        {{'8','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};

    cout << solution.isValidSudoku(sudoku) << endl;

    return EXIT_SUCCESS;
}