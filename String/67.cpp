#include <string>
#include <iostream>
using namespace std;


//Find online
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(a.size() == 0 && b.size() == 0){
        	return "";
        }
        string res = a.size()>b.size()?a:b; //get long string
        string str = a.size()>b.size()?b:a; //get short string
        bool carry=false;
        int i=str.size()-1;  // set index
        int j=res.size()-1;  // set index
        while (i>=0){
            if (res[j]=='1' && str[i]=='1'){res[j]=carry?'1':'0';carry=true;i--;j--;continue;}
            if (res[j]=='0' && str[i]=='0'){res[j]=carry?'1':'0';carry=false;i--;j--;continue;}
            if (res[j]=='0' && str[i]=='1'){res[j]=carry?'0':'1';i--;j--;continue;}
            if (res[j]=='1' && str[i]=='0'){res[j]=carry?'0':'1';i--;j--;continue;}
        }
        while (j>=0 && carry){
            if (res[j]=='1'){res[j]='0';j--;continue;}
            if (res[j]=='0'){res[j]='1';break;}
        }
        if (j<0 && carry){ res="1"+res;}
        return res;
    }
};


//Find online
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            // can also use below sentence 
            //s = to_string(c % 2) + res;
            c /= 2;
        }
        return s;
    }
};


int main(){

	return 0;
}