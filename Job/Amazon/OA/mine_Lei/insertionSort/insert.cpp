// Example program
#include <iostream>
#include <string>
using namespace std;

void insertSort(int nums[], int n)
{
	if (n <= 1) return;
	for(int i = 1; i < n; ++i) {
			int temp = nums[i];
			int j = i - 1;
			while (j >= 0 && temp < nums[j]) { 
				    nums[j + 1] = nums[j];
					--j;
				}
			nums[j + 1] = temp;
		}
	return ;
}

int main(int argc, char const *argv[])
{
	int nums[10] = {2, 1, 0, -1, 0, 2, 1, 6, 5, 3};
	insertSort(nums, 10);
	for (int i = 0 ; i < 10; ++i)
		cout<< nums[i] << " ";
	return 0;
}
