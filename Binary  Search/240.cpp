#include <iostream>
#include <vector>
using namespace std;

//Search a 2D Matrix II
//my code, 06/07/2016, time: nlog(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int begin = 0, end = col - 1, mid;
        for(int i = 0; i < row; ++i) {
            while(begin + 1 < end) {
                mid = begin + (end - begin) / 2;
                if(matrix[i][mid] == target) {
                    return true;
                } else if(matrix[i][mid] < target) {
                    begin = mid;
                } else {
                    end = mid;
                }
            } 
            begin = 0, end = col - 1;
            if(target == matrix[i][begin]) {
                return true;
            } else if(target == matrix[i][end]) {
                return true;
            }
        }
        return false;
    }
};


//my code, 06/07/2016, time: log(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0; 
        while( i >= 0 && j <= col - 1) {
            if(matrix[i][j] == target) {
                return true;
            } else if ( matrix[i][j] < target) {
                ++j;
            } else {
                --i;
            }
        }
        return false;
    }
};