#include <iostream>
#include <string>
using namespace std;
 
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int head = 0;
        int tail = len - 1;
        while (tail - head > 0) {
            if (s[head] >= 'A' && s[head] <= 'Z'){
                s[head] = s[head] + 'a' - 'A';
            }
            if((s[head] < 'a' && s[head] > '9') ||
                s[head] < '0' ||
                s[head] > 'z'){
                head++;
                continue;
            }
            if (s[tail] >= 'A' && s[tail] <= 'Z'){
                s[tail] = s[tail] + 'a' - 'A';
            }
            if((s[tail] < 'a' && s[tail] > '9') ||
                s[tail] < '0' ||
                s[tail] > 'z'){
                tail--;
                continue;
            }
            if (s[head] == s[tail]){
                head ++;
                tail --;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
 
int main(int argc, char const *argv[])
{
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "ace a car";
    string s3 = "ab";
    string s4 = "1a2";
    string s5 = ".a";
    string s6 = "0k.;r0.k;";
    Solution sol;
    cout << sol.isPalindrome(s6) << endl;
    return 0;
}