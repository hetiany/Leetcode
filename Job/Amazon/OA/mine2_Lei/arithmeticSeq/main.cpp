#include <iostream>
using namespace std;

int find (int* nums, int n) {
	if (n < 3) return 0;
	int left = 0, right = 1;
	int diff = nums[1] - nums[0];
	int cnt = 0;
	while (right < n - 1) {
		if (diff != nums[right + 1] - nums[right]) {
			cnt += (right - left -1) * (right - left) / 2;
			if (cnt > 1000000000) {
				return -1;
			}
		diff = nums[right + 1] - nums[right];
		left = right;
		}
		right++;
	}
	cnt += (right - left - 1) * (right - left) / 2;
	return cnt > 1000000000 ? -1 : cnt;
}
int main(int argc, char const *argv[])
{
	int arr[] = {2,5,2,3,4,6,8,10,12,9,8,7,6,2,4,8};
	cout << find(arr, 16);
	return 0;
}