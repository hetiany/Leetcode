//Given four integers, make F(S) = abs(S[0] - S[1]) + abs(S[1] - S[2]) + abs(S[2] - S[3]) to be largest.

#include <iostream>
#include <vector>
using namespace std;
vector<int> Solution(int A, int B, int C, int D)
{
	vector<int>  arr(4);
	arr[0] = A;
	arr[1] = B;
	arr[2] = C;
	arr[3] = D;
	sort(arr.begin(), arr.end());// -1 , 1, 3, 5
	swap(arr[0],arr[1]);//1, -1, 3, 5 
	swap(arr[2],arr[3]);//1, -1, 5, 3;
	swap(arr[0],arr[3]);//3, -1, 5, 1;
	return arr;
}
int main(int argc, char const *argv[])
{
	//std::{1,3,-1,5};//-1, 1, 3, 5;   1  5 -1 3
	//3 -1 5 1//4 +6 + 4
	vector<int> v = Solution(1,3,-1,5);//2 +4 +6
	for (int i = 0; i < 4; ++i)
	{
		cout<<v[i];
	}
	return 0;
}