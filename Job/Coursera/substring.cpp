//给一个字符串，输出所有连续子串中按字母顺序最大的（这题只会暴力解）
//   例如 “ab”, 子串有{"a","ab","b"}， 输出“b”
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string maxdicsubstring(string s) {
		string maxdic;
		if(s.size() == 0) {
			return maxdic;
		}
		int length = s.size();
		int curmax = length - 1;
		
		for(int i = length - 1; i >= 0; i--) {
			if(s[curmax] < s[i]) {
				curmax = i;
			} else if(s[curmax] == s[i]) {
				int  sublength = min(length - 1 - curmax, curmax - i - 1);
				//cout << "sublength " << sublength << endl;
				if(sublength <= 0) {
					curmax = i;
				} else {
					for(int j = 1; j <= sublength; ++j) {
						if(s[i + j] > s[curmax + j]) {
							curmax = i;
							break;
						} else if (s[i + j] < s[curmax + j]) {
							break;
						} else if(s[i + j] == s[curmax + j]) {
							continue;
						}
					}			
				}
			}
		}
		maxdic = s.substr(curmax);
		return maxdic;
	}
};


int main() {
	Solution a;
	cout << a.maxdicsubstring("abc") << endl;
	cout << a.maxdicsubstring("abczbzca") << endl;
	cout << a.maxdicsubstring("zcbazbaczcab") << endl;
	cout << a.maxdicsubstring("zdaczcab") << endl;

	return 0;
}