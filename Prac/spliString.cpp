// extract to string
//#include <istream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string s = "apple|orange|kiwi";
	istringstream stream(s);
	//string stream = s;
	vector<string> result;
	string tok;
	while(getline(stream, tok, '|')) {
		result.push_back(tok);
	}
	
	for(string i: result) {
		cout << i << endl;
	}

  return 0;
}