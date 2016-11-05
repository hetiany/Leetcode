//my code, 07/28/2016
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size()) {
            return 0;
        }
        int height = grid.size();
        int wide = grid[0].size();
        vector<vector<int> > record(height, vector<int>(wide, 0));
        
        record[0][0] = grid[0][0]; 
        for(int i = 1; i < height; ++i ) {
            record[i][0] = record[i -1][0] + grid[i][0]; 
        }
        for(int i = 1; i < wide; ++i) {
            record[0][i] = record[0][i -1] + grid[0][i];
        }
        
        for(int i = 1; i < height; ++i) {
            for(int j = 1; j < wide; ++j) {
                record[i][j] = min(record[i - 1][j], record[i][j - 1]) + grid[i][j];
            }
        }
        return record[height - 1][wide - 1];
    }
};