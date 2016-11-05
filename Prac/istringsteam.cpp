#include <iostream>
#include <sstream> 
#include <vector>
using namespace std;



int main() {
	/*int i, j;
	i = j = 0;
	cout << i << " " << j << endl;


	cout << sizeof(double) << endl;*/
	string store = "    aaa   bbb   vv dvd bv";
	istringstream in(store);
	string word;
	vector<string> result;
	while(in >> word) {
		if(!word.empty()) {
			result.push_back(word);
		}
	}

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

	return 0;
}