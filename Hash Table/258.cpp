//my code, 06/27/2016
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num = num / 10;
        }
        if(sum < 10 && sum >= 0) {
            return sum;
        } else {
            return addDigits(sum);
        }
    }
};


//Find online, time: O(1), space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};


//my code, 07/19/2016
class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum > 9) {
            sum = 0;
            while(num) {
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return sum;
    }
};