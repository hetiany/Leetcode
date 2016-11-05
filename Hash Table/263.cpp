//my code, 06/27/2016
class Solution {
public:
    bool isUgly(int num) {
        if(num == 1) {
            return true;
        }
        if(num == 0) {
            return false;
        }
        if(!(num % 2)) {
            num = num / 2;
        } else if(!(num % 3)) {
            num = num / 3;
        } else if(!(num % 5)) {
            num = num / 5;
        } else {
            return false;
        }
        return isUgly(num);
    }
};

//my code, 06/27/2016
class Solution {
public:
    bool isUgly(int num) {
        if(num == 1) {
            return true;
        }
        if(num == 0) {
            return false;
        }
        while(!(num % 2)) {
            num = num / 2;
        } 
        while(!(num % 3)) {
            num = num / 3;
        } 
        while(!(num % 5)) {
            num = num / 5;
        } 
        return num == 1;
    }
};