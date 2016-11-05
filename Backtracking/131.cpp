#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


//Find online
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) {
            return ret;
        }
        vector<string> path;
        dfs(0, s, path, ret);
        return ret;
    }
    void dfs(int index, string s, vector<string> path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, ret);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};


//my code, 06/05/2016
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if(s.empty()) {
            return result;
        }
        vector<string> temp;
        get_result(result, s, temp, 0);
        return result;
    }
    
    void get_result(vector<vector<string> >& result, string s, vector<string> temp, int index) {
        if(index == s.size()) {
            result.push_back(temp);
            return ;
        }
        for(int i = index; i < s.size(); ++i) {
            if(ispalin(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                get_result(result, s, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    
    bool ispalin(string s, int begin, int end) {
        while(begin < end) {
            if(s[begin] != s[end]) {
               return false;
            } else {
                 ++begin;
                 --end;
            }
        }
        return true;
    }
};



//my code, 06/18/2016
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> store;
        vector<vector<string> > result;
        if(s.empty()) {
            return result;
        }
        get_result(result, store, s, 0);
        return result;
    }
    void get_result(vector<vector<string> >& result, vector<string> store, string s, int index) {
        
        if(index == s.size()) {
            result.push_back(store);
            return ;
        }
        for(int i = index; i < s.size(); ++i) {
            if(ispalindrome(index, i , s)) {
                store.push_back(s.substr(index, i - index + 1));
                get_result(result, store, s, i + 1);
                store.pop_back();
            }
        }
    }
    bool ispalindrome(int begin, int end, string s) {
        while(begin < end) {
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



int main {
	return 0;
}