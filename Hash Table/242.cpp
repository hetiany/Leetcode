//my code, 06/28/2016, using sort, but it's slow
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//my code, 06/28/2016, using hash table
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> store;
        for(int i = 0; i < s.size(); ++i) {
            ++store[s[i]];
        }
        for(int i = 0; i < t.size(); ++i) {
            if(store.count(t[i]) == 0) {
                return false;
            } else if(store.count(t[i]) == 1) {
                if(store[t[i]] > 0) {
                    --store[t[i]];
                }
                if(store[t[i]] == 0) {
                    store.erase(t[i]);
                }
            }
        }
        return !store.size();
    }
};

//Find online
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};