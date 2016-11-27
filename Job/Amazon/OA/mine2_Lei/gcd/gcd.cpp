#include <iostream>
#include <vector>
using namespace std;
int gcd(int a , int b);
int getGCD(vector<int> arr) {
	int len = arr.size();
	if (len <= 1)
		return arr[0];
	int res = arr[0];
	for (int i = 1; i < len; ++i) {
		if (arr[i] > 0 && res > 0) {
			res = gcd(res, arr[i]);
		}
		else return 0;
	}
	return res;
}
//gcd(m,n) = gcd(n, m mod n)
int gcd(int a , int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}


int getGCD2(vector<int> nums){
	int len = nums.size();
	if (len == 0)
		return 0; 
	if (nums[0] == 0 || len <= 1)
		return nums[0];
	int result = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
				return 0;
		int m = nums[i];
		while(m % result != 0) { // 10 % 7 = 3, 7 % 3 = 4; 4 % 3 = 1; 3 % 1 == 0;
			int tmp = result;
			result = m % result;
			m = tmp;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout<<getGCD2({27, 81, 9});
	return 0;
}