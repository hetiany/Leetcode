//Find online, 06/27/2016
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) {
            	return false;
            }
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};


//my code, 06/27/2016
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        
        for(int i = 0; i < s.size(); ++i) {
            if(s_map.find(s[i]) == s_map.end() && t_map.find(t[i]) == t_map.end()) {
                s_map[s[i]] = i;
                t_map[t[i]] = i;
            } else if(s_map.find(s[i]) != s_map.end() && t_map.find(t[i]) != t_map.end()) {
                if(s_map[s[i]] == t_map[t[i]]) {
                    s_map[s[i]] = i;
                    t_map[t[i]] = i;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};