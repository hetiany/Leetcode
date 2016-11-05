//my code, 06/14/2016, can be accepted, but not correct
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) {
            return 0;
        }
        if(x > 0) {
            return sqrt(x);
        }
        return 0;
    }
};


//Find online
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int left = 1, right = INT_MAX;
        while (true) {
            int mid = left + (right - left)/2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x / (mid + 1)) {
                    return mid;
                }
                left = mid + 1;
            }
        }
    }
};


//Find online
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 1, right = x;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mid <= x / mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};


//Find online
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};


//jiuzhang
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
            
        long left = 0;
        long right = x;
        long mid;
        while (left + 1 < right) {
            mid = left + (right - left)/2; 
            if (x > mid * mid) {
                left = mid;
            } else if (x < mid * mid) {
                right = mid;
            } else {
                return mid;
            }
        }
        return left;
    }
};


//my code, 06/14/2016, this method is better
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) {
            return 0;
        }
        int left = 1, right = x;
        long mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(mid * mid == x) {
                return mid;
            } else if(mid * mid < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};