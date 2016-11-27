//S = "ADOBECCODEBANC"
//T = "ABC"

//ADOBEC
//BECCODEBA
//ODEBANC
//BANC
//Lei
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> mp(128, 0);
        for(auto c : t) mp[c]++;
        int start = 0, end = 0, minStart = 0, minLen = INT_MAX, count = m;
        while (end < n) {
            if (mp[s[end]] > 0) count--;
            mp[s[end]]--;
            end++;
            while (count == 0) {
                if (end - start < minLen) {  
                    minStart = start;         
                    minLen = end - start;
                }
                if (mp[s[start]] == 0) {
                    count++;
                }         
                mp[s[start++]]++;
            }
        }
        if (minLen == INT_MAX) return "";
        return s.substr(minStart, minLen);
    }
};


//my code, 11/17/2016
//"bba"   "ab", this example can explain why ++mp[s[start]] should be outside of "if condition"
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for(auto c : t) {
            ++mp[c];
        }
        int start = 0, end = 0, minStart = 0, minLen = INT_MAX;
        int n = s.size(), count = t.size();
        while(end < n) {
            if(mp[s[end]] > 0) {
                --count;
            }
            --mp[s[end]];
            ++end;
            while(count == 0) {
                if(end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                if(mp[s[start]] == 0) {
                    ++count;
                    // ++mp[s[start]];
                }
                ++mp[s[start]];
                ++start;
            }
        }
        if(minLen == INT_MAX) {
            return "";
        }
        return s.substr(minStart, minLen);
    }
};


//my code, 10/23/2016, error
class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> record;
        unordered_map<char, int> temp;
        for(int i = 0; i < t.size(); ++i) {
            ++record[t[i]];
        }
        temp = record;
        int start = 0, len = 0, count = t.size(), len_min = INT_MAX, start_min = 0; 
        for(int i = 0; i < s.size(); ++i) {
            if(temp.find(s[i]) != temp.end()) {
                if(count == t.size()) {
                    start = i;
                }
                --count;
                ++len;
                if(--temp[s[i]] == 0) {
                    temp.erase(s[i]);
                }
            } else {
                if(len != 0) {
                    ++len;
                }
            }
       
            if(temp.size() == 0) {
                temp = record;
                count = t.size();
                if(len < len_min) {
                    len_min = len;
                    start_min = start;
                    //count = t.size();
                    //len = 0;
                }
                len = 0;
            }
        }
        if(len_min == INT_MAX) {
            return res;
        }
        res = s.substr(start_min, len_min);
        return res;
    }
};