#include <string>
#include <iostream>
#include <cstring>
using namespace std;
 
class Solution {
public:
    string countAndSay(int n) {
        this -> counter = n - 1;
        this -> ss = "1";
        countAndSayRec(ss);
        return ss;
    }
private:
    int counter;
    string ss;
    void countAndSayRec(string s){
        if(counter == 0) return;
        string tmp;
        int i = 0;
        int pre = s[0] - '0';
        int idx[9];
        memset(idx, 0, sizeof(idx)/sizeof(int));
        while(s[i] != '\0'){
            if(s[i] - '0' == pre){
                ++idx[pre];
            } else {
                tmp.push_back(char(idx[pre] + '0'));
                tmp.push_back(char(pre + '0'));
                idx[pre] = 0;
                pre = s[i] - '0';
                ++idx[pre];
            }
            ++i;
        }
        tmp.push_back(char(idx[pre] + '0'));
        tmp.push_back(char(pre + '0'));
        --counter;
        ss = tmp;
        countAndSayRec(tmp);
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.countAndSay(8) << endl;
    return 0;
}