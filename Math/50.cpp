//Find online, double myPow
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        double t = myPow(x,n/2);
        if(n % 2) {
            return n < 0 ? 1 / x * t * t : x * t * t;
        }
        else {
           return t * t; 
        }
    }
};


//Lei
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
            x = 1 / x;
            if(n == INT_MIN) {
                return (myPow(x, INT_MAX) * x);
            }
            n = -n;//cause overflow
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2):myPow(x * x, (n - 1) / 2) * x;
    }
};


//my code, 06/14/2016
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        if( n == 1) {
            return x;
        }
        if(n < 0) {
            return 1 / x * myPow(1 / x, -(n + 1) );
        }
        if(n > 0) {
            return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
        }
        return 0;
    }
};