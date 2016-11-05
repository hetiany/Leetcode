//my code
class Solution {
public:
    int reverse(int x) {
        long result = 0;
            while(x / 10 || x % 10) {
                result = result * 10 + x % 10;
                x = x /10;
            }
            if(result > INT_MAX) {
                return 0;
            } else if(result < INT_MIN) {
                return 0;
            } else {
                return result;
            }
        return 0;
    }
};


//find online
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};