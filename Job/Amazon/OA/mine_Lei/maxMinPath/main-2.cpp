	int Path(vector<vector<int> >& matrix) {
		int m = matrix.size();						
		int n = m ? 0 : matrix[0].size();
		int dp[m][n];
		int **dp = new int*[m];
		for (int i = 0; i < m; ++i) {
			dp[i] = new int[n]();
		}

		fill_n(dp, m * n, 0);
		dp[0][0] = matrix[0][0]
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