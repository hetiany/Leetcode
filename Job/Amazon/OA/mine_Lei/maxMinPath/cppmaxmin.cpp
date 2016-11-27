// Example program
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector> 
#include <algorithm>
using namespace std;

int minmax(vector<vector<int> > matrix) {
	    int m = matrix.size();						
		int n = m ? matrix[0].size() : 0 ;
		//int dp[m][n];
		// int **dp = new int*[m];
		// for (int i = 0; i < m; ++i) {
		// 	dp[i] = new int[n]();
		// }
		int ** dp = new int *[m];
		dp[0] = new int[m * n];
		for (int i = 1; i < m; ++i) {
			dp[i] = dp[i - 1] + n;
		}

		//fill_n(dp, m * n, 0);
		dp[0][0] = matrix[0][0];
		for (int i = 1; i < m; ++i) {
			dp[i][0] = min (dp[i - 1][0], matrix[i][0]); 
		}
		for (int j = 1; j < n; ++j) {
			dp[0][j] = min (dp[0][j - 1], matrix[0][j]);
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[i][j] = max (min(dp[i - 1][j], matrix[i][j]), min (dp[i][j - 1], matrix[i][j]));
			}
		}
		return dp[m - 1][n - 1];

}

int main(int argc, char const *argv[])
{
    vector< vector<int> > matrix;
    int a[3] = {8, 4, 7};
    int b[3] = {6, 5, 9};
    vector<int> v1(a, a + 3);
    vector<int> v2 (b, b + 3);
    matrix.push_back(v1);
    matrix.push_back(v2);
    cout<<minmax(matrix);
    return 0;
}