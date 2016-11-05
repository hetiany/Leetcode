//Find online
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};



//my code, 08/26/2016
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) {
            return s;
        }
        int left = 0, right = 0;
        int maxlen = 0, maxstart = 0;
        int total = s.size();
        for(int start = 0; start < total - maxlen / 2;) {
            left = start, right = start;
            while(right + 1 < total && s[right] == s[right + 1]) {
                ++right;
            }
            start = right + 1;
            while(right + 1 < total && left - 1 >= 0 && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            if(right - left + 1 > maxlen) {
                maxlen = right - left + 1;
                maxstart = left;
            }
        }
        return s.substr(maxstart, maxlen);
    }
};

//my code, 10/17/2016
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        if(s.size() == 0 || s.size() == 1) {
            return s;
        }
        int left = 0, right = 0;
        for(int i = 0; i < s.size();) {
            left = i;
            while(i + 1 < s.size() && s[i] == s[i + 1]) {
                ++i;
            }
            right = i;
            i = i + 1;
            while(left - 1 >=0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            string temp = s.substr(left, right - left + 1);
            res = res.size() > temp.size() ? res : temp;
        }
        return res;
    }
};