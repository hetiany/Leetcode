#include <string>
#include <iostream>
using namespace std;
 
class Solution {
public:
    string addBinary(string a, string b) {
        int idxa = a.size() - 1;
        int idxb = b.size() - 1;
        int carry = 0;
        int current = 0;
        string s = "";
        while(idxa > -1 && idxb > -1){
            current = a[idxa] + b[idxb] + carry - '0' - '0';
            if(current >= 2){
                current -= 2;
                carry = 1;
            } else carry = 0;
            s = char(current + '0') + s;
            --idxa;
            --idxb;
        }
        if(idxa == -1 && idxb > -1){
            while(idxb > -1){
                current = b[idxb] + carry - '0';
                if(current >= 2){
                    current -= 2;
                    carry = 1;
                } else carry = 0;
                s = char(current + '0') + s;
                --idxb;
            }
        }
        if(idxa > -1 && idxb == -1){
            while(idxa > -1){
                current = a[idxa] + carry - '0';
                if(current >= 2){
                    current -= 2;
                    carry = 1;
                } else carry = 0;
                s = char(current + '0') + s;
                --idxa;
            }
        }
        if(carry == 1) s = '1' + s;
        return s;
    }
};
 
 
int main(int argc, char const *argv[])
{
    string a = "1010";
    string b = "1011";
    Solution sol;
    string x = sol.addBinary(a, b);
    cout << x << endl;
    // cout << sol.addBinary(a, b) << endl;
    return 0;
}