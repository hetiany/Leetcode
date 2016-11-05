#include <iostream>
#include <string>
using namespace std;

//Can also use KMP ???, hash code(need to implement the hash function first)
class Solution {
public:
    int strStr(string haystack, string needle) {
    	int hLen = haystack.size();
    	int nLen = needle.size();
        if( hLen == 0 && nLen == 0 ){
        	return 0;
        }
        if(nLen > hLen){
        	return -1;
        }
        //notice +1, loop num, renew ptr every time
        for(int i = 0; i < hLen-nLen+1; ++i ){
        	char* ptr = &haystack[i];
        	int j = 0;
        	for(; j < nLen; ++j){
        		if(*ptr == needle[j]){
        			ptr++;
        		}else{
        			break;
        		}
        	}
        	if(j == nLen){
        		return i;
        	}
        }
 		return -1;
    }
};


int main(){
    string a("abcd");
    string b("a");
    Solution sol;
    cout << sol.strStr(a,b) << endl;
	return 0;
}