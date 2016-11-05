#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//Word Search
//Find online
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M,N,i,j,sLen = word.size();
        if( (M = board.size()) && (N = board[0].size()) && sLen) {
            for(i = 0; i < M; ++i)
                for(j = 0; j < N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen) {
        char curC;
        bool res = false;
        if( (curC = board[row][col]) != word[start]) return false;
        if(start==sLen-1) return true;
        board[row][col] = '*';
        if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
};



//my code, This code is accepted
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty() || board.empty()) {
            return false;
        }
        for(int i = 0; i < board.size(); ++i) {
        	for(int j = 0; j < board[0].size(); ++j) {
        		if(get_result(board, word, i, j, 0) ) {
        		    return true;
        		}
        	}
        }
        return false;
    }

    bool get_result(vector<vector<char> >& board, string word, int start_x, int start_y, int word_pos) {
        bool result = false;
    	char temp '' = board[start_x][start_y];
    	if(temp != word[word_pos]) {
    		return false;
    	}
    	if(word_pos == word.size() - 1) {
    		return true;
    	}
    	if(temp == word[word_pos]) {
    		board[start_x][start_y] = '*';
			if(!result && start_x > 0) {
				result = get_result(board, word, start_x - 1, start_y, word_pos + 1);
			}
			if(!result && start_x < board.size() - 1) {
				result = get_result(board, word, start_x + 1, start_y, word_pos + 1);
			}
			if(!result && start_y > 0) {
				result = get_result(board, word, start_x , start_y - 1, word_pos + 1);
			}
			if(!result && start_y < board[0].size() - 1) {
				result = get_result(board, word, start_x, start_y + 1, word_pos + 1);
			}
			board[start_x][start_y] = temp;
    	}		
		return result;
    }
}; 

//my code, 09/25/2016
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) {
            return false;
        }
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(get_result(board, visited, word, row, col, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool get_result(vector<vector<char> >& board, vector<vector<bool> >& visited, string word, int row, int col, int i, int j, int index) {
        if(board[i][j] != word[index]) {
            return false;
        }
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        if(board[i][j] == word[index]) {
            if(index == word.size() - 1) {
                return true;
            }
            visited[i][j] = true;
            for(int k = 0; k < 4; ++k) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && x < row && y >= 0 && y < col && !visited[x][y]) {
                    if(get_result(board, visited, word, row, col, x, y, index + 1)) {
                        return true;
                    }
                }
            }
            visited[i][j] = false;
        }
        return false;
    }
};


//my code, time limit exceed
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        //int pos_x = 0;
        //int pos_y = 0;
        if(board.size() && board[0].size() && word.size()) {
            for(int i = 0; i < board.size(); ++i) {
            	for(int j = 0; j < board[0].size(); ++j) {
                    get_result(result, board, word, i, j, 0);
            	}
            }
        }
        return result;
    }

    void get_result(bool& result, vector<vector<char> >& board, string word, int start_x, int start_y, int word_pos) {
        //bool result = false;
    	char temp = board[start_x][start_y];
    	if(temp != word[word_pos]) {
    		return ;
    	}
    	if(word_pos == word.size() - 1) {
    		return ;
    	}
		board[start_x][start_y] = '*';
		if(!result && start_x > 0) {
			get_result(result, board, word, start_x - 1, start_y, word_pos + 1);
		}
		if(!result && start_x < board.size() - 1) {
			get_result(result, board, word, start_x + 1, start_y, word_pos + 1);
		}
		if(!result && start_y > 0) {
			get_result(result, board, word, start_x , start_y - 1, word_pos + 1);
		}
		if(!result && start_y < board[0].size() - 1) {
	        get_result(result, board, word, start_x, start_y + 1, word_pos + 1);
		}
		board[start_x][start_y] = temp;
		//return result;
    }
};

int main() {
	return 0;
}

















