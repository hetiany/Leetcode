#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
 
 
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vec;
        int n = strs.size();
        if(n <= 1) return vec;
        unordered_map<string, int> map;
        for(int i = 0; i < n; ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(map.find(s) == map.end())
                //map.insert(make_pair(s, i));
                map[s] = i;
             else{
                if(map[s] >= 0){
                    vec.push_back(strs[map[s]]);
                    map[s] = -1;
                }
                vec.push_back(strs[i]);
            }
        }
        return vec;
    }
};
 
void printVector(vector<string> v){
    vector<string>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << "\n"  << endl;
}
 
int main(int argc, char const *argv[])
{
    /*vector<string> v = {
        "tom marvolo riddle ",
        "i am lord voldemort",
        "acdbgfe"
    };*/
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //printVector(v);
    Solution sol;
    printVector(sol.anagrams(v));
    return 0;
}