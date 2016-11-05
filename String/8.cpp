#include <iostream>
#include <climits>
using namespace std;

//Liu
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;
        //int maxdiv10 = INT_MAX / 10;
        int i = 0;
        while(str[i] == ' '){
            ++i;  
        }

        if(str[i] == '-') {
            sign = -1;
            ++i;
        } else if(str[i] == '+'){
            ++i;
        } 

        while(str[i] != '\0'){
            if(isInteger(str[i])){
                res = res * 10 + str[i] - '0';
            } else{ 
              break; 
            }

            if(isOverFlow(res)){
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            ++i;
        }

        return res * sign;
    }

    bool isInteger(char c){
        return (c <= '9' && c >= '0');
    }

    bool isOverFlow(long i){
        return (i > INT_MAX || i < INT_MIN);
    }
};


//my code, 07/18/2016, changed by find online answer
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int sign = 1;
        int i = 0;
        while (str[i] == ' ') { i++; }
        if(str[i] == '+') {
            ++i;
        } else if(str[i] == '-') {
            ++i;
            sign = -1;
        }
        while('0' <= str[i] && str[i] <= '9') {
            result = result * 10 + (str[i++] - '0');
            if(result * sign >= INT_MAX) return INT_MAX;
            if(result * sign <= INT_MIN) return INT_MIN;                
        }
        return result*sign;
    }
};



//my code, 08/26/2016
class Solution {
public:
    int myAtoi(string str) {
        if(!str.size()) {
            return 0;
        }
        long result = 0;
        int begin = 0;
        while(str[begin] == ' ') {
            ++begin;
        }
        
        int sign = 1;
        if(str[begin] == '-') {
            sign = -1;
            ++begin;
        } else if(str[begin] == '+') {
            sign = 1;
            ++begin;
        }
        
        while(str[begin] >= '0' && str[begin] <= '9') {
            result = result * 10 + str[begin] - '0';
            ++begin;
            if(result * sign >= INT_MAX) {
                return INT_MAX;
            }
            if(result * sign <= INT_MIN) {
                return INT_MIN;
            }
        }
        return result * sign;
    }
};



// non-integral num character cannot be put at the head of the string
int main(){
  Solution sl;
  string s = " b11228552307";
  string a = "-123abc";
  cout << sl.myAtoi(s) << endl;
  cout << sl.myAtoi(a) << endl;
  return 0;
}