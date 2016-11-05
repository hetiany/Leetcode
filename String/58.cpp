#include <iostream>
#include <string>
using namespace std;
 
class Solution {
public:
    int lengthOfLastWord(string s){
        if(s.size() == 0){
            return 0;
        }
        int count = 0;
        bool flag = true;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == ' '){
                flag = false;
            }else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                if(flag == false){
                    count = 0;
                    flag = true;
                }
                ++count;
            }
        }
        return count;
    }
};

int main(){

    return 0;
}