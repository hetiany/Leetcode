//my code, 06/27/2016, time limit exceeded, time: O(n*n)
class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        for(int i = 2; i <= n - 1; ++i) {
            if(isprime(i)) {
                ++result;
            }
        }
        return result;
    }
    
    bool isprime(int num) {
        if(num == 1) {
            return false;
        }
        for(int i = 2; i <= num - 1; ++i) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
};


//my code, time limit exceeded, time: O(n*sprt(n))
class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        for(int i = 1; i < n; ++i) {
            if(isprime(i)) {
                ++result;
            }
        }
        return result;
    }
    
    bool isprime(int num) {
        if(num == 1) {
            return false;
        }
        for(int i = 2; i * i <= num; ++i) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
};



//Find online, this method is better
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};



//Find online
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if(i > upper) {
                    continue;
                }
                for(int j = i * i; j < n; j += i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};


//my code, 07/06/2016
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>store(n, true);
        for(int i = 2; i * i < n; ++i) {
            if(!store[i - 1]) {
                continue;
            }
            for(int j = i * i; j < n; j += i) {
                store[j - 1] = false;
            }
        }
        int count = 0;
        for(int i = 2; i < n; ++i) {
            if(store[i - 1]) {
                ++count;
            }
        }
        return count;
    }
};