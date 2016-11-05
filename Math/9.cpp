//my code, 07/18/2016
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int store = x;
        int sum = 0;
        int rest = 0;
        while(x != 0) {
            rest = x % 10;
            x = x / 10;
            sum = sum * 10 + rest;
        }
        if(sum == store) {
            return true;
        }
        return false;
    }
};

//Find online
class Solution {
public:
    bool isPalindrome(int x) {
        if(!x) return true;
        if(x < 0 || 0 == x % 10 ) return false;
        int y = 0;
        while(x > y) {
            y = y * 10 + x % 10;
            if(x == y) return true; // to deal with odd digits case, e.g. 232
            x = x / 10; 
        }
        return x == y; // to deal with even digits case, e.g. 22
    }
}; 


//my code, 08/25/2016
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int store = x;
        int palin_x = 0;
        while(x) {
            palin_x = palin_x * 10 + x % 10;
            x = x / 10;
        }
        
        return store == palin_x ? true : false;
    }
};