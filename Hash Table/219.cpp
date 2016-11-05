#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0){return false;}
        unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); ++i){
        	if(mapping.find(nums[i]) == mapping.end()){
        		mapping[nums[i]] = i;
        	}else{ if( i-mapping[nums[i]] <= k ){
        		 	return true;
        			}else{
        				mapping.erase(nums[i]);
        				mapping[nums[i]] = i;
        			}

        	}
        }
       return false; 
    }
};


//my code, 07/06/2016
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for(int i = 0; i < nums.size(); ++i) {
            if(store.count(nums[i]) && k >= i - store[nums[i]]) {
                return true;
            } else {
                store[nums[i]] = i;
            }
        }
        return false;
    }
};



int main(){
	return 0;
}