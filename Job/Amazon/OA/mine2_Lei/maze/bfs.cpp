#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int maze(vector<vector<int> > & grid) {
	int m = grid.size();
	int n = m ? grid[0].size() : 0;
	vector<vector<bool> > visited (m, vector<bool> (n, false));
	if (grid[0][0] == 0) return -1;
	queue<pair<int, int> > que;
	que.push(make_pair(0,0));
	while (!que.empty()) {
		pair<int,int> p = que.front();
		if (grid[p.first][p.second] == 9)
			return 1;
		visited[p.first][p.second] = true;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = p.first + dirs[i][0];
			int y = p.second + dirs[i][1];
			if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] && !visited[x][y])
				que.push(make_pair(x, y));
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	 vector<vector<int> > grid = {
                      {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 9},
                      {0, 0, 1, 1, 1},
                      {0, 0, 1, 1, 0} };
       cout << maze(grid);
	return 0;
}