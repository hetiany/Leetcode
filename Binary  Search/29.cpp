//29. Divide Two Integers
//Find online, diffcult to understand
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};



//my code, 06/14/2016, similar to above answer
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) {
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == -1 ) {
            return INT_MAX;
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int result = 0;
        long temp = dvs;
        long multi = 1;
        while(dvd >= dvs) {
            while(dvd >= (temp << 1) ) {
                temp <<= 1;
                multi <<= 1;
            } 
            dvd -= temp;
            result += multi;
            temp = dvs;
            multi = 1;
        }
        return sign == 1 ? result : -result;
    }
};