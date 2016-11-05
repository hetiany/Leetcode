#include <iostream>
#include <climits>
using namespace std;
 

 
class Solution {
public:
    int atoi(const char *str) {
        long long res = 0;
        int sign = 1;
        int maxdiv10 = INT_MAX / 10;
        while(*str == ' ') ++str;
        if(*str == '-') {
            sign = -1;
            ++str;
        } else if(*str == '+') ++str;

        while(*str != '\0'){
            if(isInteger(*str))
                res = res * 10 + *str - '0';
            else break;
            if(isOverFlow(res))
                return sign == -1 ? INT_MIN : INT_MAX;
            ++str;
        }
        return res * sign;
    }

    bool isInteger(char c){
        return (c <= '9' && c >= '0');
    }

    bool isOverFlow(long long i){
        return (i > INT_MAX || i < INT_MIN);
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sl;
    const char s[] = " b11228552307";
    cout << sl.atoi(s) << endl;
    return 0;
}