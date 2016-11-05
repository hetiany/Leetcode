//my code, 07/16/2016
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        while(n > 1) {
            if(n & 1) {
                return false;
            } else {
                n >>= 1;
            }
        }
        return true;
    }
};


//Find online, this is better
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n-1));
    }
};


//my code, 07/19/2016
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) {
            return false;
        }
        while(n > 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                return false;
            }
        }
        return true;
    }
};