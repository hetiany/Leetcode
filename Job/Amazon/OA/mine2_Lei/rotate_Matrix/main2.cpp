#include <iostream>
#include <vector>
using namespace std;
int** rotate(int matrix[][5], int m, int n, int flag) {
	int ** res = new int*[n];
	res[0] = new int [m * n];
	for (int i = 1; i < n; ++i) {
		res[i] = res[i - 1] + m;
	}
	if (flag == 1) {
		for (int i = 0 ; i < m / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap (matrix[i][j], matrix[m - i - 1][j]);
			}
		}
	} else {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
	}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			res[j][i] = matrix[i][j];
	return res;
}

int main(int argc, char const *argv[])
{
	int t[][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
	int m = 3, n = 5;
	int ** test = rotate (t, m, n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
				cout << test[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}