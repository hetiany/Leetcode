#include <iostream>
using namespace std;
 
class Solution {
public:
    int lengthOfLastWord(const char * s){
        int counter = 0;
        for(int i = 0; s[i] != '\0'; ++i){
            if(s[i] == ' ' && isALetter(s[i+1]))
                counter = 0;
            if(isALetter(s[i])) counter++;
        }
        return counter;
    }
    bool isALetter(const char c){
        if(c >= 'a' && c <= 'z'
        || c >= 'A' && c <= 'Z') return true;
        return false;
    }
};