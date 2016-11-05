#include <iostream>
#include <cstring>
using namespace std;
 
class Solution{
public:
    int strStr(char * haystack, char * needle){
        cout << strlen(needle) << endl;
        cout << strlen(haystack) << endl;

        for(int i = 0; ; ++i){
            for(int j = 0; ; ++j){
                if(j == strlen(needle)) return i;
                if(i + j == strlen(haystack)) return -1;
                if(needle[j] != haystack[i+j]) break;
            }
        }
    
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sol;
    char n[] = "a";
    char h[] = "a";
    //cout << n << h << endl;
    cout << sol.strStr(h, n) << endl;
    return 0;
}