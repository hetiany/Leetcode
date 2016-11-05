#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

//segment fault ???????
int main() {
	string a = "123";
	cout << a << endl;
	vector<string> record;
    //string record;
    for(int i = 0; i < 9; ++i) {
        //record[i] = to_string(i + 1);
        record.push_back(to_string(i + 1));
        //record += to_string(i + 1);
        cout << record[i] << endl;
    }

	return 0;
}