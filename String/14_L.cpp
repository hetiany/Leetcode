#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        //if you don't check if the vector is empty
        //there will be a run time error
        if (strs.empty())return "";
        vector<string>::iterator it;
        bool same = true;
        int i = 0;
        while (same) {
            char refer = (*strs.begin())[i];
            for (it = strs.begin(); it != strs.end(); ++it){
                if (!(*it)[i]){
                    same = false;
                    break;
                }
                same = same && ((*it)[i] == refer);
            }
            if (same){
                ++i;
            }
        }
        //string str ((*strs.begin()).begin(), (*strs.begin()).begin() + i);
        string str (strs.begin() -> begin(), strs.begin() -> begin() + i);
        return str;
    }
};
 
int main(int argc, char const *argv[])
{
    std::vector<string> v;
    v.push_back("a");
    v.push_back("asddas");
//    v.push_back("asdf");
//    cout << v.begin()[1] << endl;
    Solution sol;
    cout << sol.longestCommonPrefix(v) << endl;
    return 0;
}