#include <iostream>
#include <list>
//#include <iterator>
//#include<algorithm>
using namespace std;
//list<int> iterator findItr()

int count(int *arr, int n, int size) {
	if (n == 0) return 0;
	list<int> cache;
	list<int> :: iterator itr;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		//itr = findItr(cache.begin(), cache.end(), arr[i]);
		for (itr = cache.begin(); itr != cache.end(); ++itr)
		    if ((*itr) == arr[i]) break;
		if (itr == cache.end()) {
			count++;
			if (cache.size() == size)
				cache.pop_back();
		} else {
			cache.erase(itr);
		}
	cache.push_front(arr[i]);
	}
	return count;
}
int main(int argc, char const *argv[])
{
    int num[7] = {1,2,3,4,5,4,1};
	cout<<count(num,7, 3);
	return 0;
}
