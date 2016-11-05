#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


//Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.empty()){return false;}
    	unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); ++i){
        	mapping[nums[i]] = i; 
        }
        if(mapping.size() < nums.size()){
        	return true;
        }
        //cout << mapping.size() << endl;
        /*for(int i=0; i<nums.size(); ++i){
        	if(mapping.find(nums[i]) != mapping.end()){
        		mapping.erase(nums[i]);
        	}else{
        		return true;
        	}
        }*/
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.empty()){return false;}
    	unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); ++i){
        	mapping[nums[i]] = i; 
        }        
        cout << mapping.size() << endl;
        cout << mapping[1] << endl;
        for(int i=0; i<nums.size(); ++i){
        	if(mapping.find(nums[i]) != mapping.end()){
        		mapping.erase(nums[i]);
        	}else{
        		return true;
        	}
        }
        return false;
    }
};


//my code, 07/06/2016
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> store;
        for(int i = 0; i < nums.size(); ++i) {
            if(store.find(nums[i]) == store.end()) {
                store.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};


//Find online
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();  
    }
};

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	Solution sol;
	cout << sol.containsDuplicate(a) << endl;
	return 0;
}