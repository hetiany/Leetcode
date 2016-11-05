#include <iostream>
using namespace std;


//Find Online
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        // 4:IV, 9:IX, 40:XL, 90:XC, 400:CD, 900:CM,
        // 1:I, 10:X, 100:C, 1000:M
        int res=0;
        char pre = ' ';
        for(int i=0;i<s.size();i++){
            if (s[i]=='M' && pre!='C') {res+=1000;}
            if (s[i]=='C' && pre!='X') {res+=100;}
            if (s[i]=='X' && pre!='I') {res+=10;}
             
            if (s[i]=='M' && pre=='C') {res+=800;}
            if (s[i]=='C' && pre=='X') {res+=80;}
            if (s[i]=='X' && pre=='I') {res+=8;}
             
            if (s[i]=='I' ) {res+=1;}
             
            if (s[i]=='V' && pre!='I'){res+=5;}
            if (s[i]=='L' && pre!='X'){res+=50;}
            if (s[i]=='D' && pre!='C'){res+=500;}
             
            if (s[i]=='V' && pre=='I'){res+=3;}
            if (s[i]=='L' && pre=='X'){res+=30;}
            if (s[i]=='D' && pre=='C'){res+=300;}
             
            pre = s[i];
             
        }
         
        return res;
    }
};

//Find online
class Solution {
public:
    int romanToInt(string s) {
        int map[26];
        map['I' - 'A'] = 1; map['V' - 'A'] = 5; map['X' - 'A'] = 10; map['L' - 'A'] = 50;
        map['C' - 'A'] = 100; map['D' - 'A'] = 500; map['M' - 'A'] = 1000;
        int res = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(map[s[i] - 'A'] >= map[s[i + 1] - 'A']) {
                res += map[s[i] - 'A'];
            } else {
                res -= map[s[i] - 'A'];
            }
        }
        return res;
    }
};

//my code, 09/25/2016
class Solution {
public:
    int romanToInt(string s) {
        if(!s.size()) {
            return 0;
        }
        unordered_map<int, int> store;
        store['I' - 'A'] = 1;
        store['V' - 'A'] = 5;
        store['X' - 'A'] = 10;
        store['L' - 'A'] = 50;
        store['C' - 'A'] = 100;
        store['D' - 'A'] = 500;
        store['M' - 'A'] = 1000;
        int res = store[s[0] - 'A'];
        for(int i = 1; i < s.size(); ++i) {
            if(store[s[i] - 'A'] > store[s[i - 1] - 'A']) {
                res += store[s[i] - 'A'] - 2 * store[s[i - 1] - 'A'];
            } else {
                res += store[s[i] - 'A'];
            }
        }
        return res;
    }
};

int main(){



	return 0;
}