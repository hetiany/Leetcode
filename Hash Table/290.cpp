//my code, 06/28/2016, but it's a little bit slower
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m_pattern;
        unordered_map<string, int> m_str;
        
        vector<string> get_str;
        istringstream in(str);
        string word;
        while(in >> word) {
            get_str.push_back(word);
        }
        if(pattern.size() != get_str.size()) {
            return false;
        }
        for(int i = 0; i < pattern.size(); ++i) {
            if(m_pattern.count(pattern[i]) == 0 && m_str.count(get_str[i]) == 0 ) {
                m_pattern[pattern[i]] = i;
                m_str[get_str[i]] = i;
            } else if(m_pattern.count(pattern[i]) > 0 && m_str.count(get_str[i]) > 0 ) {
                if(m_pattern[pattern[i]] == m_str[get_str[i]]) {
                    m_pattern[pattern[i]] = i;
                    m_str[get_str[i]] = i;
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


//my code, 06/28/2016. 0ms, this is method is better
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m_pattern;
        unordered_map<string, int> m_str;
        
        istringstream in(str);
        string word;
        int index = 0;
        while(in >> word) {
            if(index == pattern.size()) {
                return false;
            }
            if( m_pattern.count(pattern[index]) == 0 && m_str.count(word) == 0 ) {
                m_pattern[pattern[index]] = index;
                m_str[word] = index;
                ++index;
            } else if(m_pattern.count(pattern[index]) == 1 && m_str.count(word) == 1) {
                if(m_pattern[pattern[index]] == m_str[word]) {
                     m_pattern[pattern[index]] = index;
                     m_str[word] = index;
                     ++index;
                } else {
                    return false;
                }
            } else {
                return false;
            }
            
        }
        cout << index << endl;
        return index == pattern.size();
    }
};



//Find online
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};


//Changed based on online answer
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word]) {
                return false;   
            }
            p2i[pattern[i]] = i + 1;
            w2i[word] = i + 1;
        }
        if(i == n) {
            return true; 
        } else {
            return false;
        };
    }
};
