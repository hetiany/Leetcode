//Find online
class Solution {
public:
        int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};


//my code, 06/27/2016
class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = get_num(slow);
            fast = get_num(get_num(fast));
        } while(fast != slow);
        if(fast == 1) {
            return true;
        } else {
            return false;
        }
    }
    int get_num(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
};