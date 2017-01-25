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
	int i = 0;
	while(in >> word) {
		cout << i++ << endl;
		if(!word.empty()) {
			result.push_back(word);
		}
	}
	cout << "rest: " << in << endl;
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

	return 0;
}