//Find online, DFS
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < grid.size(); ++ i) {
            for(int j = 0; j < grid[0].size(); ++ j)
            if(grid[i][j] == '1') {
                ++ res;
                DFS(grid, i, j);
            }
        }
        return res;
    }
    
    void DFS(vector<vector<char> > &grid, int x, int y) {
        grid[x][y] = '0';
        //search down
        if(x > 0 && grid[x - 1][y] == '1') {
            DFS(grid, x - 1, y);
        }
        
        //search up
        if(x < grid.size() - 1 && grid[x + 1][y] == '1') {
            DFS(grid, x + 1, y);  
        }
        
        //search left
        if(y > 0 && grid[x][y - 1] == '1') {
            DFS(grid, x, y - 1); 
        }

        //search right
        if(y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
            DFS(grid, x, y + 1);
        }
    }
};

//my code, 07/07/2016, using visited matric, DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) {
            return 0;
        }
        int row = grid.size(), column = grid[0].size();
        int result = 0;
        vector<vector<bool> > visited(row, vector<bool>(column, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    ++result;
                    search(grid, visited, i, j);
                }
            }
        }
        return result;
    }
    
    void search(vector<vector<char> >& grid, vector<vector<bool> >& visited, int row, int column) {
        visited[row][column] = true;
        if(row > 0 && grid[row - 1][column] == '1' && visited[row - 1][column] == false) {
            search(grid, visited, row - 1, column);
        }
        if(row < grid.size() - 1 && grid[row + 1][column] == '1' && visited[row + 1][column] == false) {
            search(grid, visited, row + 1, column);
        }
        if(column > 0 && grid[row][column - 1] == '1' && visited[row][column - 1] == false) {
            search(grid, visited, row, column - 1);
        }
        if(column < grid[0].size() - 1 && grid[row][column + 1] == '1' && visited[row][column + 1] == false) {
            search(grid, visited, row, column + 1);
        }
    }
};


//Lei, this is better, DFS
class Solution {
public:
     int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
     int numIslands(vector<vector<char> >& grid)
     {
        int m = grid.size(), n = m ? grid[0].size() : 0; 
        int count = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                    {
                        visit(grid, m, n, i, j, visited);
                        count++;
                    }
            }
            return count;
     }

     void visit(vector<vector<char> > & grid, int& m, int& n, int i, int j, vector<vector<bool> > & visited)
     {
        visited[i][j] = true;
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == '1' && !visited[x][y] )
                visit(grid, m, n, x, y, visited);
        }
        return;
     }
};


//BFS, my code, 09/22/2016
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    ++res;
                    BFS(row, col, i, j, grid, visited);
                }
            }
        }
        return res;
    }
    void BFS(int row, int col, int i, int j, vector<vector<char> >& grid, vector<vector<bool> >& visited) {
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[i][j] = true;
        queue<vector<int> > store;
        store.push({i,j});
        while(store.size()) {
            i = store.front()[0];
            j = store.front()[1];
            store.pop();
            for(int k = 0; k < 4; ++k) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && x < row && y >= 0 && y < col && !visited[x][y] && grid[x][y] == '1') {
                    store.push({x,y});
                    visited[x][y] = true;
                }
            }
        }
        return ;
    }
};


//Find online, BFS
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j) {
                if(grid[i][j] == '1') {
                    ++ res;
                    BFS(grid, i, j);
                 }
            }
        return res;
     }

    void BFS(vector<vector<char>> &grid, int x, int y) {
        queue<vector<int> > q;
        q.push({x, y});
        grid[x][y] = '0';
        while(!q.empty()) {
            x = q.front()[0], y = q.front()[1];
            q.pop();
            if(x > 0 && grid[x - 1][y] == '1') {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
             }
             if(x < grid.size() - 1 && grid[x + 1][y] == '1') {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
             }
             if(y > 0 && grid[x][y - 1] == '1') {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
             }
             if(y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
             }
       }
    }
};

//my code, 07/11/2016, BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size()) {
            return 0;
        }
        int result = 0;
        int row = grid.size(), column = grid[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                if(grid[i][j] == '1') {
                    ++result;
                    get_num(grid, i, j, row, column);
                }
            }
        }
        return result;
    }
    
    void get_num(vector<vector<char>>& grid, int i, int j, int row, int column) {
       queue<vector<int> > store;
       store.push({i, j});
       grid[i][j] = '0';  
       vector<int> temp;
       while(!store.empty()) {
           temp = store.front();
           store.pop();
           if(temp[0] > 0 && grid[temp[0] - 1][temp[1]] == '1') {
               store.push({temp[0] - 1, temp[1]});
               grid[temp[0] - 1][temp[1]] = '0';
           }
           if(temp[0] < row - 1 && grid[temp[0] + 1][temp[1]] == '1') {
               store.push({temp[0] + 1, temp[1]});
               grid[temp[0] + 1][temp[1]] = '0';
           }
           if(temp[1] > 0 && grid[temp[0]][temp[1] - 1] == '1') {
               store.push({temp[0], temp[1] - 1});
               grid[temp[0]][temp[1] - 1] = '0';
           }
           if(temp[1] < column - 1 && grid[temp[0]][temp[1] + 1] == '1') {
               store.push({temp[0], temp[1] + 1});
               grid[temp[0]][temp[1] + 1] = '0';
           }
       }
       
    }
};


//dfs, 10/17/2016
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        vector<vector<bool> > record(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1' && record[i][j] == false) {
                    dfs(grid, record, row, col, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char> >& grid, vector<vector<bool> >& record, int row, int col, int i, int j) {
        record[i][j] = true;
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= 0 && x < row && y >=0 && y < col && grid[x][y] == '1' && record[x][y] == false) {
                dfs(grid, record, row, col, x, y);
            }
        }
    }
};