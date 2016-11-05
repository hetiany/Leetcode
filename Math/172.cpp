//Find online
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long i = 5; n / i > 0; i *= 5){
            result += n / i;
        }
        return result;
    }
};


//Find online
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;  
        while(n >= 5){  
            n /= 5;  
            count += n;  
        }  
        return count;
    }
};