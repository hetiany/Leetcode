#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<int, int> a;
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	//cout << a[0] << endl;
	auto n = a.begin();
	cout << n -> first << endl;


	unordered_map<int, int>:: iterator ptr = a.begin();
	cout << ptr -> first << endl;

	//ptr = &a[1]; error
	//cout << ptr -> first << endl;
	return 0;
}