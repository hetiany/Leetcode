//给一个int[][]的matirx，对于一条从左上到右下的path p_i，p_i中的最小值是m_i，求所有m_i中的最大值。只能往下或右
//比如：
//[8, 4, 7]
//[6, 5, 9]
//有3条path：
//8-4-7-9 min: 4
//8-4-5-9 min: 4
//8-6-5-9 min: 5
//return: 5.
//dp[i][j] means the  min number among all the pathes to the  M[i][j]; 

a b m  r
0 1 2  1
0 2 1  1
1 0 2  1
1 2 0  2
2 1 0  2
2 0 1  1
class MaxMinPath {
	int Path(vector<vector<int> >& matrix){
	int m = matrix.size(), n = m ? matrix[0].size() : 0;
	int dp[m][n];
	fill_n(dp, m * n, 0);
	dp[0][0] = matrix[0][0];
	for (int i = 1; i < m; ++i) {
		dp[i][0] = min (dp[i - 1][0], matrix[i][0]);
	}

	for (int j = 1; j < n; ++j) {
		dp[0][j] = min(dp[0][j - 1], matrix[0][j]);
	}

	for(int i=1;i<m;i++) {
		for(int j=1;j<n;j++) {
		 dp[i][j] = max (min(dp[i-1][j], matrix[i][j]), min(dp[i][j-1], matrix[i][j]));
		}

	// for (int i = 1; i < m; ++i)
	// 	for (int j = 1; j < n; ++j)
	// 	{
	// 		if (matrix[i][j] > dp[i - 1][j] && matrix[i][j] > dp[i][j - 1]);
	// 			dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
	// 		else
	// 			dp[i][j] = matrix[i][j];
	// 	}


}



















