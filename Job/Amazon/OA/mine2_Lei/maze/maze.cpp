//2D array（0是墙，1是路，9是吃的）🐭从（0，0）到到吃的，是否有此path存在
#include <iostream>
#include <vector>
using namespace std;

static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs (vector<vector<int> >& grid, vector<vector<bool> >& visited, int i , int j)
{
	if (grid[i][j] == 9)
		return true;
	visited[i][j] = true;
	for (int d = 0; d < 4; ++d)
	{
		int x = i + dirs[d][0];
		int y = j + dirs[d][1];
		if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] && !visited[x][y]) {
			visited[x][y] = true;
			if (dfs(grid, visited, x, y)) return true;
		}
	}
	return false;
}

int maze(vector<vector<int> > & grid) {
	int m = grid.size();
	int n = m ? grid[0].size() : 0;
	vector<vector<bool> > visited(m, vector<bool> (n, false));
	if (grid[0][0] == 0) return false;
	if (dfs (grid, visited, 0, 0))
		return 1;
	return -1; 
}



int main(int argc, char const *argv[])
{
	 vector<vector<int> > grid = {
                      {1, 0, 0, 1, 1},
                      {1, 1, 0, 0, 1},
                      {0, 0, 1, 0, 1},
                      {0, 9, 1, 1, 9} };
       cout << maze(grid);
	return 0;
}