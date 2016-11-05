#include <vector>
#include <string>
#include <iostream>
using namespace std;
 
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
            s += '(';
            helper(leftnum - 1, rightnum);
            //s.pop_back();
        }
        if(rightnum > 0){
            s += ')';
            helper(leftnum, rightnum - 1);
            //s.pop_back();
        }
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> v;
    v = sol.generateParenthesis(2);
    vector<string>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << "haha" << endl;
    return 0;
}