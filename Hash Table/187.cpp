//my code, 07/15/2016, using hash table
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size() <= 10) {
            return result;
        }
        unordered_map<string, int> store;
        string n;
        for(int i = 0; i <= s.size() - 10; ++i) {
            n.insert(n.begin(), s.begin() + i, s.begin() + i + 10);
            if(store.find(n) != store.end()) {
                if(store[n] == 1) {
                    result.push_back(n);
                }
                ++store[n];
            } else {
                ++store[n];
            }
            n.clear();
        }
        return result;
        
    }
};


//Find online, using bit, cannot understand????
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        for (int t = 0, i = 0; i < s.size(); i++)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                r.push_back(s.substr(i - 9, 10));
        return r;
    }
};
