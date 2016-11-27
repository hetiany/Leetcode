#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int get(string a, string b) {
		int len_a = a.size();
		int len_b = b.size();
		if(!len_a || !len_b) {
			return -1;
		}
		for(int i = 0; i < len_a - len_b + 1; ++i) {
			char* p = &a[i];
			int j;
			for(j = 0; j < b.size(); ++j) {
				if(b[j] == '*') {
					++p;
					continue;
				}
				if(b[j] != '*' && b[j] == *p) {
					++p; 
				} else {
					break;
				}
			}
			if(j == b.size()) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;
	cout << sol.get("thisisa test", "*s**") << endl;
	return 0;
}