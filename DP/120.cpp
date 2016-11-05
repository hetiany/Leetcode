//should use some kinds of method

//using traversal, time limit exceed
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = INT_MAX;
        dfs(triangle, result, 0, 0, 0);
        return result;
    }
    void dfs(vector<vector<int> >& triangle, int& result, int x, int y, int sum) {
        if(x == triangle.size()) {
            result = min(result, sum);
            return ;
        }
        dfs(triangle, result, x + 1, y, sum + triangle[x][y]);
        dfs(triangle, result, x + 1, y + 1, sum + triangle[x][y]);
    }
};


//using divide and conquer, time limit exceed
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return divideConquer(triangle, 0, 0);
    }
    int divideConquer(vector<vector<int> >& triangle, int x, int y) {
        if(x == triangle.size()) {
            return 0;
        }
        return triangle[x][y] + min(divideConquer(triangle, x + 1, y), divideConquer(triangle, x + 1, y + 1));
    }
};


//using divide and conquer + memorization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int> > hash(height, vector<int>(height, INT_MAX));
        return divideConquer(triangle, 0, 0, hash);
        
    }
    int divideConquer(vector<vector<int> >& triangle, int x, int y, vector<vector<int> >& hash) {
        if(x == triangle.size()) {
            return 0;
        }
        if(hash[x][y] != INT_MAX) {
            return hash[x][y];
        }
        hash[x][y] = triangle[x][y] + min(divideConquer(triangle, x + 1, y, hash), divideConquer(triangle, x + 1, y + 1, hash));
        return hash[x][y];
    }
};


//using DP, top-down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int> > record(height, vector<int>(height, 0));
        record[0][0] = triangle[0][0];
        for(int i = 1; i < height; ++i) {
            record[i][0] = record[i - 1][0] + triangle[i][0];
            record[i][i] = record[i - 1][i - 1] + triangle[i][i];
        }
        for(int i = 1; i < height; ++i) {
            for(int j = 1; j < i; ++j) {
                record[i][j] = min(record[i - 1][j - 1], record[i - 1][j]) + triangle[i][j];
            }
        }
        int result = record[height - 1][0];
        for(int i = 1; i < height; ++i) {
            if(result > record[height -1][i]) {
                result = record[height -1][i];
            }
        }
        return result;
    }
};

