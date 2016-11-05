//my code, 07/28/2016
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 && n == 0) {
            return 0;
        }
        vector<vector<int> > record(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            record[i][0] = 1; 
        }
        for(int i = 0; i < n; ++i) {
            record[0][i] = 1; 
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                record[i][j] = record[i - 1][j] + record[i][j - 1];
            }
        }
        return record[m - 1][n - 1];
    }
};