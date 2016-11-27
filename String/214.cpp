//my code, 11/23/2016, time limit exceeded
class Solution {
public:
    string shortestPalindrome(string s) {
        if(!s.size()) {
            return "";
        }
        string res;
        int left = 0, right = 0, len = INT_MIN, n = s.size();
        while(right < n) {
            if(isPalindrome(left, right, s)) {
                len = max(len, right - left + 1);
            }
            ++right;
        }
        if(len == n) {
            return s;
        }
        string add = s.substr(len, n - len);
        reverse(add.begin(), add.end());
        res = add + s;
        return res;
    }
    
    bool isPalindrome(int begin, int end, string s) {
        while(begin <= end) {
            if(s[begin] == s[end]) {
                ++begin;
                --end;
            } else {
                return false;
            }
        }
        return true;
    }
};


//Lei, KMP ???
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        vector<int> p(l.size(), 0);
        int len = 0;
        for (int i = 1; i < l.size(); ) {
            if (l[i] == l[len]) {
                p[i] = ++len;
                ++i;
            } else if (len == 0) {
                p[i] = 0;
                ++i;
            }
            else len = p[len - 1];
        }
        return rev_s.substr(0, n - p[l.size() - 1]) + s;
    }
};

//Find online
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return s;
        
        int i = n;
        string v = s; 
        reverse(v.begin(), v.end());  //Reverse s.
        
        for(; i >= 1; --i) {
            if(s.substr(0, i) == v.substr(n - i)) break;    //palindrome?
        }
        for(; i < s.size(); i += 2) {
            s = s[i] + s;   //Construct
        }
        return s;
    }
};