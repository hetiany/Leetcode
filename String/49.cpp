#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
 
 
/*class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vec;
        vector<vector<string> > groupvec;
        int n = strs.size();
        if(n <= 1) return vec;
        unordered_map<string, int> map;
        for(int i = 0; i < n; ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(map.find(s) == map.end()){
                //map.insert(make_pair(s, i));
                map[s] = i;
                vec.push_back(strs[i]);
            }                
             else{
                //if(map[s] >= 0){
                 //   vec.push_back(strs[map[s]]);
                // map[s] = -1;
                //}
                vec.push_back(strs[i]);
            }
        }
        return vec;
    }
};*/


//Find online
//Group Anagrams
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<string> > hashMap;
        //put the elements of strs in the hashmap
          for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(strs[i]);
        }
        //put the hashmap in the result and sort the result
        vector<vector<string> > result(hashMap.size());
        //vector<vector<string> > result;
        int k = 0;
        unordered_map<string, vector<string> >::iterator it;
        for(it = hashMap.begin(); it != hashMap.end(); ++it, ++k) {

            //result[k].push_back(*(it->second));
            result[k].swap(it->second);
            sort(result[k].begin(), result[k].end());
        }
        return result;
    }
};


//my code, 07/15/2017
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > hashMap;
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(strs[i]);
        }
        vector<vector<string> > result(hashMap.size());
        int c = 0;
        for(auto a: hashMap) {
            for(auto b: a.second) {
                result[c].push_back(b);
            }
            ++c;
        }
        return result;
    }
};


//my code, 10/24/2016
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string> > res;
         if(!strs.size()) {
             return res;
         }
         unordered_map<string, vector<string> > store;
         string temp;
         for(int i = 0; i < strs.size(); ++i) {
             temp = strs[i];
             sort(temp.begin(), temp.end());
             store[temp].push_back(strs[i]);
         }
         
         for(auto ptr: store) {
             res.push_back(ptr.second);
         }
         return res;
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
    //printVector(sol.groupAnagrams(v));
    return 0;
}