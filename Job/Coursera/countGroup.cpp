#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countGroup(vector<vector<int> >& matrix, vector<int>&q) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix.front().size();
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        queue<int> queue;
        unordered_map<int, int> dict;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int res = 0;
                    queue.push(i * n + j);
                    visit[i][j] = true;

                    while (!q.empty()) {
                        int tmp = q.front();
                        res++;
                        queue.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = tmp / n + dir[k][0];
                            int y = tmp % n + dir[k][1];
                            if (x < 0 || y < 0 || x >= n || x >= m || matrix[x][y] != 1 || visit[x][y]) {
                                continue;
                            }
                            queue.push(x * n + y);
                            visit[tmp / n][tmp % n] = true;
                        }
                    }
                    dict[res]++;
                }
            }
        }

        for (int t: q) {
            res.push_back(dict[t]);
        }
        return res;
    }
};

int main() {
    return 0;
}