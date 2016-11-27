#include <iostream>
//#include <vector>
using namespace std;
//一个cell，如果左右两边数一样，则被设置为0，不一样则为1，求第n天cell array的值
int* change (int *arr, int n, int days) {
	if (n <= 1)
		return arr;
	int cnt = 0;
	while (cnt < days) {
		int *tmp = new int[n];
		for (int i = 0; i < n; ++i) {
			int left = 0, right = 0;
			if (i > 0) 
				left = arr[i - 1];
			if (i < n - 1)
				right = arr[i + 1];
			tmp[i] = left ^ right;
		}
		arr = tmp;
		cnt++;
	}
	return arr;
}

int main(int argc, char const *argv[])
{
	//vector<int> arr ={1, 0, 0, 0, 0, 1, 0, 0};
	int arr[] = {1, 0, 0, 0, 0, 1, 0, 0};
	int days = 8;
	//vector<int> res = change (arr, days);
	int * res = change(arr, 8, days);
	//for (auto& i : res)
	for (int i = 0; i < 8; ++i)
		cout << res[i] << " ";
//output: [0, 1, 0, 0, 1, 0, 1, 0]
	return 0;
}