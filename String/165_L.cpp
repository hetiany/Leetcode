#include <iostream>
using namespace std;
 
string nextSubstr(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str.at(i) == '.') {
                return str.substr(i + 1);
            }
        }
        return "0";
    }
 
int main(int argc, char const *argv[])
{
    string s = "12.34.56.78";
    cout << stoi(s) << endl;
    cout << stoi(nextSubstr(s)) << endl;
    return 0;
}