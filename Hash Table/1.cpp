#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

//Two Sum
//Find online
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mapping;  
      vector<int> result;  
      if(!nums.size()) {
          return result;
      }
      for(int i = 0; i< nums.size(); i++)  
      {  
        mapping[nums[i]] = i;  
      }  
      for(int i = 0; i < nums.size(); i++)  
      {  
        int searched = target - nums[i];  
        if(mapping.find(searched) != mapping.end() && i != mapping[searched])  
        {  
          result.push_back(i);  
          result.push_back(mapping[searched]);  
          //break;
          return result;  
        }  
      }  
      return result;          
    }
};

void printVector(vector<int> v){
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

//Liu, Better
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> vec;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            int numberToFind = target - nums[i];
            if(map.find(numberToFind) != map.end()){
                vec.push_back(map[numberToFind]);
                vec.push_back(i);
                return vec;
            }
            map[nums[i]] = i;
        }
        return vec;
    }
};


//my solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() < 2) {
            return result;
        }
        unordered_map<int, int> mapping;
        for(int i = 0; i < nums.size(); ++i) {
            int rest = target - nums[i];
            if( mapping.find(rest) == mapping.end() ) {
                mapping[nums[i]] = i;
            } else {
                result.push_back(mapping[rest]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};


int main() {
	unordered_map<int, int> m;
    
 	m[0] = 1;
 	m[1] = 2;
 	m[0] = 3;
 	//cout << m[0] << m[1] << m[2] << m[4] << endl;

 /* map<int, int> n;
  n[0] = 1;
 	n[1] = 2;
 	n[2] = 1;
 	cout << n[0] << n[1] << n[2] << endl;*/

  unordered_map<int, int> mm;
    
  mm[2] = 0;
  mm[3] = 1;
  mm[4] = 0;
  //cout << mm[2] << mm[3] << mm[4] << endl;




    Solution sol;
    vector<int> v;
    //v.push_back(1);
    //v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    //v.push_back(3);
    //v.push_back(5);
    //v.push_back(6);
    //v.push_back(7);
    //cout << v[0] << v[1] << v[2] << endl;

    vector<int> res;
    res = sol.twoSum(v, 6);
    printVector(res);
	return 0;
}