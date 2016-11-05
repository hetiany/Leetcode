//A square number 1+3+5+7+.......
//Find online
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};


//my code, 08/26/2016
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) {
            return true;
        }
        long begin = 1, end = num, mid = 0;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(mid * mid > num) {
                end = mid;
            } else if(mid * mid < num) {
                begin = mid;
            } else {
                return true;
            }
        }
        if( (begin * begin) == num) {
            return true;
        }
        if( (end * end) == num) {
            return true;
        }
        return false;
        
    }
};