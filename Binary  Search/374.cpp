// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int begin = 1, end = n, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(guess(mid) == 0) {
                return mid;
            } else if(guess(mid) == 1) {
                begin = mid;
            } else if(guess(mid) == -1) {
                end = mid;
            }
        }
        if(guess(begin) == 0) {
            return begin;
        } else if(guess(end) == 0) {
            return end;
        }
        return 0;
    }
};




//Find online
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) return n;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2, t = guess(mid);
            if (t == 0) return mid;
            else if (t == 1) left = mid;
            else right = mid;
        }
        return left;
    }
};