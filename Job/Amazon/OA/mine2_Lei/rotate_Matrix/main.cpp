//1 clockwise 
void rotate(vector < vector<int> > & matrix, int flag)
{
	int m = matrix.size(), n = m ?  matrix[0].size() : 0;
	if (flag == 1)
	{
		reverse (matrix.begin(), matrix.end());
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < n; ++i)
				swap(matrix[i][j], matrix[j][i]);
	}
	else { // anti clock wise;
		for (auto row : matrix) reverse(row.begin(), row.end());
			for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < n; ++i)
				swap(matrix[i][j], matrix[j][i]);
	}
return;
}

for(int i = 0; i < m; i++){
				for(int j = 0; j < n/2; j++){
					matrix[i][j] ^= matrix[i][n-j-1];
					matrix[i][n-j-1] ^= matrix[i][j];
					matrix[i][j] ^= matrix[i][n-j-1];
				}
			}