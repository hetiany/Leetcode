//Find online, BFS
class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int width = board.size();
        if(width == 0) {
            return;
        }//Add this to prevent run-time error!
            
        int length = board[0].size();
        if(length == 0) {
            return;
        }// Add this to prevent run-time error!
            
    
        for (int i = 0; i < length; ++i) {
            if (board[0][i] == 'O') {
                bfsBoundary(board, 0, i);
            }
            if (board[width - 1][i] == 'O') {
                bfsBoundary(board, width - 1, i);
            }
        }
    
        for (int i = 0; i < width; ++i) {
            if (board[i][0] == 'O') {
                bfsBoundary(board, i, 0);
            }
            if (board[i][length - 1] == 'O') {
                bfsBoundary(board, i, length - 1);
            }
        }
    
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }

     void bfsBoundary(vector<vector<char> >& board, int w, int l) {
        int width = board.size();
        int length = board[0].size();
        deque<pair<int, int> > q;
        q.push_back(make_pair(w, l));
        board[w][l] = 'B';
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();
            pair<int, int> adjs[4] = {{cur.first - 1, cur.second}, 
                {cur.first + 1, cur.second}, 
                {cur.first, cur.second - 1},
                {cur.first, cur.second + 1}};
                
            for (int i = 0; i < 4; ++i) {
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if ((adjW >= 0) && (adjW < width) && (adjL >= 0)
                        && (adjL < length) 
                        && (board[adjW][adjL] == 'O')) {
                    q.push_back(make_pair(adjW, adjL));
                    board[adjW][adjL] = 'B';
                }
            }
        }
    }
};


//Find online, DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int row=board.size();
        if(!row)
            return;
        int col=board[0].size();

        for(i=0;i<row;i++){
            check(board,i,0,row,col);
            if(col>1)
                check(board,i,col-1,row,col);
        }
        for(j=1;j+1<col;j++){
            check(board,0,j,row,col);
            if(row>1)
                check(board,row-1,j,row,col);
        }
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='1')
                    board[i][j]='O';
    }
    void check(vector<vector<char> >&vec,int i,int j,int row,int col){
        if(vec[i][j]=='O'){
            vec[i][j]='1';
            //notice here, i > 1, j > 1
            if(i>1)
                check(vec,i-1,j,row,col);
            if(j>1)
                check(vec,i,j-1,row,col);
            if(i+1<row)
                check(vec,i+1,j,row,col);
            if(j+1<col)
                check(vec,i,j+1,row,col);
        }
    }
};


//Lei, DFS
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        if (m <= 2 || n <= 2) return;
        vector<vector<bool> > visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; ++i)         
        {
            if (board[i][0] == 'O' && !visited[i][0])
             {
                //visited[i][0] = 1;
                dfs(board, visited, m, n, i, 0);
             }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
             {
                //visited[i][n - 1] = 1;
                dfs(board, visited, m, n, i, n - 1);
             }
        }
         //cout<<"sss"<<endl;
        // cout<<n<<endl;
        for (int i = 0; i < n; ++i) 
        {
            cout<< i<<endl;
            if (board[0][i] == 'O' && !visited[0][i])
             {
                //visited[0][i] = 1;
                dfs(board, visited, m, n, 0, i);
             }
            if (board[m - 1][i] == 'O' && !visited[m - 1][i])
             {
                 //visited[m - 1][i] = 1;
                dfs(board, visited, m, n, m - 1, i);
             }
       } 

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '+')
                    board[i][j] = 'O';
                
            }
            return;
    }

    void dfs(vector<vector<char> > & board, vector<vector<bool> >& visited, int m, int n, int x, int y)
    {   
        board[x][y] = '+';
        visited[x][y] = 1;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};
        int p = x, q = y;
        for (int i = 0; i < 4; ++i)
        {
            p = x + dir[i][0];
            q = y + dir[i][1];
            //notice here, 0 < p, not 0 <= p
            if ( 0 < p && p < m && 0 < q && q < n && board[p][q] == 'O' && !visited[p][q])
                {
                    //visited[p][q] = 1;
                    dfs(board, visited, m, n, p, q);
                }
        }
        return;
    }
};

//my code, DFS, 07/11/2016
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size()) {
            return ;
        }
        int row = board.size(), column = board[0].size();
        
        for(int i = 0; i < row; ++i) {
            if(board[i][0] == 'O') {
                helper(board, i, 0, row, column);
            }
            if(board[i][column - 1] == 'O') {
                helper(board, i, column - 1, row, column);
            }
        }
        
        for(int i = 0; i < column; ++i) {
            if(board[0][i] == 'O') {
                helper(board, 0, i, row, column);
            }
            if(board[row - 1][i] == 'O') {
                helper(board, row - 1, i, row, column);
            }
        }
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '+') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
    
    void helper(vector<vector<char> >& board, int i , int j, int row, int column) {
        board[i][j] = '+';
        if(i > 1 && board[i - 1][j] == 'O') {
            helper(board, i - 1, j, row, column);
        }
        if(i < row - 1 && board[i + 1][j] == 'O') {
            helper(board, i + 1, j, row, column);
        }
        if(j > 1 && board[i][j - 1] == 'O') {
            helper(board, i, j - 1, row, column);
        }
        if(j < column - 1 && board[i][j + 1] == 'O') {
            helper(board, i, j + 1, row, column);
        }
    }
};

//my code, 07/11/2016, DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size()) {
            return ;
        }
        int row = board.size(), column = board[0].size();
        
        for(int i = 0; i < row; ++i) {
            if(board[i][0] == 'O') {
                helper(board, i, 0, row, column);
            }
            if(board[i][column - 1] == 'O') {
                helper(board, i, column - 1, row, column);
            }
        }
        
        for(int i = 0; i < column; ++i) {
            if(board[0][i] == 'O') {
                helper(board, 0, i, row, column);
            }
            if(board[row - 1][i] == 'O') {
                helper(board, row - 1, i, row, column);
            }
        }
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '+') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
    
    void helper(vector<vector<char> >& board, int i , int j, int row, int column) {
        board[i][j] = '+';
        if(i > 1 && board[i - 1][j] == 'O') {
            helper(board, i - 1, j, row, column);
        }
        if(i < row - 2 && board[i + 1][j] == 'O') {
            helper(board, i + 1, j, row, column);
        }
        if(j > 1 && board[i][j - 1] == 'O') {
            helper(board, i, j - 1, row, column);
        }
        if(j < column - 2 && board[i][j + 1] == 'O') {
            helper(board, i, j + 1, row, column);
        }
    }
    //tow method for helper function
    /*void helper(vector<vector<char> >& board, int i , int j, int row, int column) {
        board[i][j] = '+';
        if(i > 0 && board[i - 1][j] == 'O') {
            helper(board, i - 1, j, row, column);
        }
        if(i < row - 2 && board[i + 1][j] == 'O') {
            helper(board, i + 1, j, row, column);
        }
        if(j > 0 && board[i][j - 1] == 'O') {
            helper(board, i, j - 1, row, column);
        }
        if(j < column - 2 && board[i][j + 1] == 'O') {
            helper(board, i, j + 1, row, column);
        }
    }*/
};

//my code, 09/22/2016, DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size()) {
            return ;
        } 
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            if(!visited[i][0] && board[i][0] == 'O') {
                dfs(board, visited, i, 0, row, col);
            }
            if(!visited[i][col-1] && board[i][col-1] == 'O') {
                dfs(board, visited, i, col-1, row, col);
            }
        }
        for(int i = 0; i < col; ++i) {
            if(!visited[0][i] && board[0][i] == 'O') {
                dfs(board, visited, 0, i, row, col);
            }
            if(!visited[row-1][i] && board[row-1][i] == 'O') {
                dfs(board, visited, row-1, i, row, col);
            }
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == '+') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
    void dfs(vector<vector<char> >& board, vector<vector<bool> >& visited, int i, int j, int row, int col) {
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        board[i][j] = '+';
        visited[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x > 0 && x < row && y > 0 && y < col && !visited[x][y] && board[x][y] == 'O') {
                dfs(board, visited, x, y, row, col);
            }
        }
        return ;
    }
};