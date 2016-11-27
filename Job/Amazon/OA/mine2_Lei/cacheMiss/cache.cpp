#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int count(int *arr, int n, int size) {
	if (n == 0) return 0;
	list <int> cache;int count = 0;
	for (int i = 0; i < n; ++i) {
			list<int> :: iterator it = find(cache.begin(), cache.end(), arr[i]);
			if (it == cache.end()) {
				count++;
				if (cache.size() == size)
				cache.pop_front();
			} else {
			    cache.erase(it);
			}
		cache.push_back(arr[i]);
	}
	return count;
}
int main(int argc, char const *argv[])
{
    int num[7] = {1,2,3,4,5,4,1};
	cout<<count(num,7, 3);
	return 0;
}