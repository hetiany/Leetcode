#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


//Single Number, runing time error
/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()){return false;}
        int result;
    	unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); ++i){
        	if(mapping.find(nums[1]) != mapping.end()){
        		mapping[nums[i]] = i; 
        	}else{
        		mapping.erase(nums[i]);
        	}
        }
        unordered_map<int, int>:: iterator itr = mapping.begin();
        result = itr->second;
        return result ;
    }
};*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int size = nums.size();
      int left = nums[0];  
      for(int i =1; i < size; i++)  
      {  
        left = left ^ nums[i];  
      }  
      return left;
    }
};

int main(){
	return 0;
}