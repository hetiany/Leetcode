//my code, 07/19/2017
class Solution {
public:
    int titleToNumber(string s) {
        int total = s.size();
        int res = 0, temp = 0;
        for(int i = total - 1; i >= 0; --i) {
            temp = res;
            res = (1 + s[i] - 'A') * pow(26, total - 1 - i);
            res = res + temp;
        }
        return res;
    }
};

//Find online
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result = result * 26 + (s[i] - 'A' + 1);
        }
        return result;
    }
};