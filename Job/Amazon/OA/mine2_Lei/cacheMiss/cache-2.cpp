#include <iostream>
#include <list>
#include <vector>
using namespace std;

int count(int *arr, int n, int size) {
	if (n == 0) return 0;
	list <int> cache;
	for (int i = 0; i < n; ++i) {
			list<int> iterator :: it = find(cache.begin(), cache.end(), arr[i]);
			if (it == cache.end()) {
				count++;
				if (list.size() == size)
				cache.pop_front();
			} else {
			    cache.erase(*it);
			}
		cache.push_back(arr[i]);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}main