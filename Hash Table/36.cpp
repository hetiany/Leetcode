#include <iostream>
#include <vector>
using namespce std;

//Find online
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num]) {
                        return false;
                    }
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
    }
};

//my code, 07/05/2016
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool column[9][9] = {false};
        bool sub[9][9] = {false};
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if(row[i][num] || column[j][num] || sub[k][num]) {
                        return false;
                    }
                    row[i][num] = column[j][num] = sub[k][num] = true;
                }
            }
        }
        return true;
    }
};