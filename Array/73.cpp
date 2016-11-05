//my code, 10/24/2016, sapce: O(mn)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool> > record(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == 0 && record[i][j] == false) {
                    for(int k = 0; k < col; ++k) {
                        if(matrix[i][k] != 0) {
                            matrix[i][k] = 0;
                            record[i][k] = true;
                        }
                    }
                    for(int k = 0; k < row; ++k) {
                        if(matrix[k][j] != 0) {
                            matrix[k][j] = 0;
                            record[k][j] = true; 
                        }
                    }
                }
            }
        }
    }
};


//find online, space O(1)
//leave the first column
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) col0 = 0;
                for (int j = 1; j < cols; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = matrix[0][j] = 0;
                    }
                }
        }
        
        for (int i = rows - 1; i >= 0; i --) {
            for (int j = cols - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};