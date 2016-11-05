//Lei
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
    	vector<int> res;
    	int rowBegin = 0, rowEnd = m - 1;
    	int colBegin = 0, colEnd = n - 1;
    	while (rowBegin <= rowEnd && colBegin <= colEnd) {
    		//right
    		for (int j = colBegin; j <= colEnd; ++j) {
    			res.push_back(matrix[rowBegin][j]);
    		}
    		rowBegin++;
    
    		for (int i = rowBegin; i <= rowEnd; ++i) {
    			res.push_back(matrix[i][colEnd]);
    		}
    		colEnd--;
            if (rowBegin <= rowEnd) {
        		for (int j = colEnd; j >= colBegin; --j) {
        			res.push_back(matrix[rowEnd][j]);
        		}
            }
    		rowEnd--;
    		if (colBegin <= colEnd) {
        		for (int i = rowEnd; i >= rowBegin; --i) {
        			res.push_back(matrix[i][colBegin]);
        		}
    		}
    		colBegin ++;
    	}
    	return res;
    }
};


//Find online
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int nr = matrix.size();     
        if (nr == 0) return res;
        int nc = matrix[0].size();  
        if (nc == 0) return res;
        
        vector<int> nSteps{nc, nr-1};
        
        int iDir = 0;   // index of direction.
        int ir = 0, ic = -1;    // initial position
        while (nSteps[iDir%2]) {
            for (int i = 0; i < nSteps[iDir%2]; ++i) {
                ir += dirs[iDir][0]; 
                ic += dirs[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir%2]--;
            iDir = (iDir + 1) % 4;
        }
        return res;
    }
};