//Find online
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        result.reserve(256);
        long long nr = numerator;
        long long dr = denominator;

        if (nr < 0 && dr > 0 || nr > 0 && dr < 0) result += '-';
        if (nr < 0) nr = -nr;
        if (dr < 0) dr = -dr;
        result += to_string(nr / dr);
        nr = nr % dr;
        if (nr == 0) return result;

        result += '.';
        vector<int> digits;
        unordered_map<int, int> cache;  // (remainder, position)
        cache[nr] = 0;
        int rpos = -1;
        while (nr != 0) {
            nr *= 10;
            if (nr < dr) {
                digits.push_back(0);
            } else {
                digits.push_back(nr / dr);
                nr = nr % dr;
                auto it = cache.find(nr);
                if (it != cache.end()) {
                    rpos = it->second;
                    break;
                }
            }
            cache[nr] = digits.size();
        }
        for (int i = 0; i < digits.size(); i++) {
            if (i == rpos) result += '(';
            result += to_string(digits[i]);
        }
        if (rpos >= 0) result += ')';
        return result;
    }
};



//Lei
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
         // zero numerator
        if (n == 0) return "0";
        string res;
        //determine the sign
        if (n < 0 ^ d < 0) res+= '-';
        // remove the sign of operands
        n = abs(n), d = abs(d);
        res += to_string(n / d);

        if(n % d == 0) return res;
        res += '.';
        unordered_map<int, int> map;
        // simulate the division process
        for (long r = n % d; r != 0; r %= d)
        {
            //meet a known remainder
            // so we reach the end of the repeating part
            if (map.count(r) > 0) {
                res.insert(res.begin() + map[r], '(');// pos ,size_t n, char c;
                res += ')';
                break;
            }
            // the remainder is first seen
            // remember the current position for it
            map[r] = res.size();
            r *= 10;
            //append the quotient digit
             res += to_string(r / d);
        }
    return res;
    }
};


//my code, 07/15/2016
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        long n = numerator, d = denominator;
        if(n == 0) {
            return "0";
        }
        if(n > 0 ^ d > 0) {
            result += "-";
        }
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        if(n % d == 0) {
            return result;
        }
        result += '.';
        unordered_map<int, int> store;
        for(long l = n % d; l != 0; l %= d) {
            if(store.count(l) > 0) {
                result.insert(result.begin() + store[l], '(');
                result += ')';
                break;
            }
            store[l] = result.size();
            l *= 10;
            result += to_string(l / d);
        }
        return result;
    }
};