#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


//Generate Parentheses
//Liu, Backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        helper(n, n);
        return this -> vec;
    }

private:
    vector<string> vec;
    string s;
    void helper(int leftnum, int rightnum){
        if(leftnum > rightnum) return;
        if(leftnum == 0 && rightnum == 0){
            vec.push_back(s);
            return;
        }
        if(leftnum > 0){
            //s += '(';
            s.push_back('(');
            helper(leftnum - 1, rightnum);
            s.pop_back();
        }
        if(rightnum > 0){
            //s += ')';
            s.push_back(')');
            helper(leftnum, rightnum - 1);
            s.pop_back();
        }
    }
};


//Find online
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
    }
};


//Time?? Space??
//my code, 05/28/2016
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        int left = n;
        int right = n;
        get_result(result, temp, left, right);
        return result;
    }
    void get_result(vector<string>& result, string temp, int l, int r) {
        if(l == 0 && r == 0) {
            result.push_back(temp);
            return ;
        }
        if(l > 0) {
            temp.push_back('(');
            get_result(result, temp, l - 1, r);
            temp.pop_back();
        }
        if(r > 0 && l < r) {
            temp.push_back(')');
            get_result(result, temp, l, r - 1);
            temp.pop_back();
        }
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> v;
    v = sol.generateParenthesis(3);
    vector<string>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << endl;
    return 0;
}