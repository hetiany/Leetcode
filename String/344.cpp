//my code
class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.size() - 1; i < s.size(), j >=0; ++i, --j) {
            if(i < j) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};



//jiu zhang
class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }
};


//recursive
class Solution {
public:
    string reverseString(string s) {
        get_result(0, s.size() - 1, s);
        return s;
    }
    void get_result(int begin, int end, string& s) {
        if(begin < end) {
            swap(s[begin], s[end]);
            get_result(begin + 1, end - 1, s);
        }
    }
};
