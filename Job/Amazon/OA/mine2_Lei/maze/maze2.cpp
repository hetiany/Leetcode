//2D array（0是墙，1是路，9是吃的）🐭从（0，0）到到吃的，是否有此path存在
#include <iostream>
#include <vector>
using namespace std;
//数组没有值传递
class Solution {
public:
	static int dirs[4][2];

	bool dfs (int grid[][5], bool ** visited, int m, int n, int i , int j) {
			if (grid[i][j] == 9) return true;
			visited[i][j] = true;
			for (int d = 0; d < 4; ++d) {
				int x = i + dirs[d][0];
				int y = j + dirs[d][1];
				if (0 <= x && x < m && 0 <= y && y < n && !visited[x][y] && grid[x][y] > 0 ) {
					if (dfs(grid, visited, m, n, x, y)) return true;
				}
			}
			return false;
	}

	int maze(int grid[][5], int m, int n ) {
		if (m == 0) return -1;
		bool **visited = new bool*[m];
		visited[0] = new bool[m * n];
		//memset(visited[0], 0, n);
		for (int i = 1; i < m; ++i)
		{
			visited[i] = visited[i - 1] + n;
		//	memset(visited[i], 0, n);
		}
		for (int i = 0; i < m; ++ i)
			for (int j = 0; j < n; ++j)
				cout<<visited[i][j]<<endl;

		return dfs(grid, visited, m, n, 0, 0);
	}
};
int Solution :: dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(int argc, char const *argv[])
{
	 // vector<vector<int> > grid = {
  //                     {1, 0, 0, 1, 1},
  //                     {1, 1, 0, 0, 1},
  //                     {0, 0, 1, 0, 1},
  //                     {0, 9, 1, 1, 9} };
	 // 	int ** grid = new int*[5];
		// grid[0] = new int [20];   
		int grid[4][5] = { {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 1},
                      {0, 0, 1, 0, 1},
                      {0, 9, 1, 1, 9} };
		Solution s;
       cout << s.maze(grid, 4, 5);
	return 0;
}