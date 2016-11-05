//my code, 10/24/2016
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int rowBeg = 0;
        int rowEnd = n - 1;
        int colBeg = 0;
        int colEnd = n - 1;
        int val = 1;
        while(rowBeg <= rowEnd && colBeg <= colEnd) {
            for(int i = colBeg; i <= colEnd; ++i) {
                res[rowBeg][i] = val;
                
                ++val;
            }
            ++rowBeg;
            for(int i = rowBeg; i <= rowEnd; ++i) {
                res[i][colEnd] = val;
                ++val;
            }
            --colEnd;
            if(rowBeg <= rowEnd) {
                for(int i = colEnd; i >= colBeg; --i) {
                    res[rowEnd][i] = val;
                    ++val;
                }
            }
            --rowEnd;
            if(colBeg <= colEnd) {
                for(int i = rowEnd; i >= rowBeg; --i) {
                    res[i][colBeg] = val;
                    ++val;
                }
            }
            ++colBeg;
        }
        return res;
    }
};