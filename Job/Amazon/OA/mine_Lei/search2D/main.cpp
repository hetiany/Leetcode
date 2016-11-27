Point1* searchInMatrix(vector<vector<int> > &matrix, int rowNum, int colNum, int TargetValue)
{
	Point1 *p = new Point1();
	int m = matrix.size();
	int n = m ?  matrix[0].size() : 0;
	int i = m - 1, j = 0;// start point;
	while (i >= 0 && j < n)
	{
		int temp = matrix[i][j];
		if (temp == TargetValue)
		{
			p -> x = j;
			p -> y = i;
			return p; 
		}
		else if (temp > TargetValue)
			i--;
		else j++;
	}
	return p;
}