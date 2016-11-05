#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Find online
class Solution {
public:
    string convert(string s, int numRows) {  
        vector<string> zz(numRows,"");
        if (numRows==1){return s;}
         
        int i=0; //for string
        int r=0; //for zz vector
        bool zig = false; // if s[i] is in "/" or "|" direction
        while (i<s.size()){
            if (r<numRows && !zig){
                zz[r]+=s[i];
                r++;
                i++;
            }else{
                if (!zig){
                    zig=true;
                    r--;
                }else{
                    r--;
                    zz[r] = zz[r]+s[i];
                    if (r==0){zig=false;r++;}
                    i++;
                }
            }
        }
        string res; //get result;
        for (int i=0;i<zz.size();i++){
            for (int j=0;j<zz[i].size();j++){
                    res = res+ zz[i][j];
            }
        }
        return res;
    }
};



//my code, 08/25/2016
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        vector<string> store(numRows);
        int total = s.size();
        int index = 0;
        bool dir = true;
        for(int i = 0; i < total;) {
            if(dir) {
                store[index].push_back(s[i]);
                if(index + 1 == numRows) {
                    dir = false;
                    --index;
                } else {
                    ++index;
                }
                ++i;
            } else if(!dir) {
                if(index == 0) {
                    dir = true;
                } else {
                    store[index].push_back(s[i]);
                    --index;
                    ++i;
                }
            }
        }
        string result;
        for(int i = 0; i < store.size(); ++i) {
            result += store[i];
        }
        return result;
    }
};


int main(){
    std::vector<string> v;
    v.push_back("abc");
    v.push_back("def");
    string a = "aaa";
    string b = "bbb";
    string c = a + b;
    cout << c << endl;
    cout << v[1][1]  << endl;


    /*string m = "edf";
    char *p = m; // error pointer p cannot point to m
    cout << *p << endl;*/

    /*char m[5] = "abcd";
    char *p = m; // pointer p can point to m
    cout << *p << endl;*/


	return 0;
}