#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty())return res;
        res = strs[0];
        for (int i = 1; i < strs.size();i++){
            res = findcommon(res, strs[i]);
        }
        return res;
    }
    string findcommon(string a, string b){
        string res;
        if(a.size() == 0 || b.size() == 0)
            return res;
 
        int len = a.size() < b.size()? a.size():b.size();
        for(int i = 0; i < len; i++){
            if(a[i] != b[i])return res;
            res.push_back(a[i]);
        }
        return res;
    }
};
 
int main(int argc, char const *argv[]){
    std::vector<string> v;
    //v.push_back("");
    v.push_back("asddas");
    v.push_back("asdf");
    cout << (*v.begin())[1] << endl;
    cout << v.begin()[1] << endl;
    cout << *v.begin() << endl;
    //cout << *v.end() << endl;
    //cout << v.begin() << endl;
    //cout << v[1] << endl;
    //Solution sol;
    //cout << sol.longestCommonPrefix(v) << endl;

    string aa = "abcd";
    aa.push_back('e');
    cout << *aa.begin() << endl;
    //cout << (*aa.begin())[4] << endl;
    cout << aa.begin()[4] << endl;
    cout << aa[4] << endl;
    cout << *aa.end() << endl;
    return 0;
}