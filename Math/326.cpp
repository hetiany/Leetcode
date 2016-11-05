//my code, 07/19/2017
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) {
            return false;
        }
        while(n > 1) {
            if(n % 3 == 0) {
                n /= 3;
            } else {
                return false;
            }
        }
        return true;
    }
};

//Find online, using recursive
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)));
    }
};

//Follow up, do it without using any loop / recursion
//Lei
class Solution {
public:
    bool isPowerOfThree(int n) {
        //why I can't us log(n)/log(3) ???
        double logRes = log10(n)/log10(3);
        return (logRes - int(logRes) == 0) ? true : false;
    }
};


//Follow up, do it without using any loop / recursion
//Find online
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int t = pow(3, (int)(log(INT_MAX)/log(3)));
        return (t % n == 0);
    }
};