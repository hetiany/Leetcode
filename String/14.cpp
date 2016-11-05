#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Bai
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
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


//my code, 09/02/2016
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        if(!strs.size()) {
            return common;
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        common = strs[0];
        for(int i = 0; i < strs.size(); ++i) {
            common = get_common(common, strs[i]);
        }
        return common;
    }
    
    string get_common(string a, string b) {
        string result;
        int length = min(a.size(), b.size());
        for(int i = 0; i < length; ++i) {
            if(a[i] == b[i]) {
                result += a[i];
            }else {
                break;
            }
        }
        return result;
    }
};



int main(){
    std::vector<string> v;
    v.push_back("cdef");
    v.push_back("cde");
    v.push_back("cdfg");
    Solution sol;
    cout << sol.longestCommonPrefix(v) << endl;
	return 0;
}