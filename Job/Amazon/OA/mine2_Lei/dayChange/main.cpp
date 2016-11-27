#include <iostream>
#include <vector>
using namespace std;
vector<int> change (vector<int> arr, int days)
{
 	if (arr.size() <= 1 || days <= 0)
	 		return arr;
	int len = arr.size();
	for (int cnt = 0; cnt < days; ++cnt)
	{
		vector<int> cur(len, 0);
		for (int i = 0; i < len; ++i)
		{
			int left = 0, right = 0;
			if (i - 1 >= 0)
				left = arr[i - 1];
			if (i + 1 <= len - 1)
				right = arr[i + 1];
			if (left == right)
				cur[i] = 0;
			else cur[i] = 1;
		}
		arr = cur;
	}
	return arr;
}

int main(int argc, char const *argv[])
{
	vector<int> arr ={1, 0, 0, 0, 0, 1, 0, 0};
	int days = 2;
	vector<int> res = change (arr, days);
	for (auto& i : res)
		cout << i << " ";
//output: [0, 1, 0, 0, 1, 0, 1, 0]
	return 0;
}