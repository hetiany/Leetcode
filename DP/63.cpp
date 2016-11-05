//my code, 07/28/2016
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(!obstacleGrid.size()) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();;
        vector<vector<int> > record(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] == 0) {
                record[i][0] = 1; 
            } else {
                break;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(obstacleGrid[0][i] == 0) {
                record[0][i] = 1; 
            } else {
                break;
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 0) {
                    record[i][j] = record[i - 1][j] + record[i][j - 1];
                } else {
                    record[i][j] = 0;
                }
            }
        }
        return record[m - 1][n - 1];
    }
};