#include <iostream>
using namespace std; 
//gcd(m, n) = gcd(m, n % m);

int getGCD(int a, int b) ;
int greatestCommonDivisor (int arr[], int n) {
	if (n == 0) return 0;
	if (n <= 1) return arr[0];
	int res = arr[0];
	for (int i = 1; i < n; ++i) {
		res = getGCD(res, arr[i]);
		if (res == 0)
			return 0;
	}	
	return res;
}

int getGCD(int a, int b) {
	if (a == 0 || b == 0) 
		return 0; 
	if (a % b == 0)
		return b;
	return getGCD(b, a % b);
}
// int greatestCommonDivisor (int arr[], int n) {
// 	if (n == 0) return 0;
// 	if (arr[0] == 0 || n <= 1) return arr[0];
// 	int res = arr[0];
// 	for (int i = 1; i < n; ++i) {
// 		if (arr[i] == 0)
// 			return 0;
// 		int m = arr[i];
// 		while (m % res != 0) {  //10 % 4;  4 % 2 
// 			int tmp = res;
// 			res = m % res;
// 			m = tmp;
// 		}
// 	}
// 	return res;
// }

int main(int argc, char const *argv[])
{
	int arr[] = {27,81, 9};
	cout<<greatestCommonDivisor(arr, 3);
	return 0;
}