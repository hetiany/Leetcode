#include <iostream>
#include <vector>
using namespace std;

//Search Insert Position

//my code, not good
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	for(int i=0; i<nums.size(); ++i){
    		if(nums[i] == target){
    			return i;
    		}
    	}

    	for(int i=0; i<nums.size(); ++i){
    		if(nums[i] > target && i <= nums.size()-1){
    			return i;
    		}
    		if(nums[i] < target && i == nums.size()-1){
    			return i+1;
    		}

    	}
    }
};


//Find online, binary search, good
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int low = 0,high = nums.size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;    	
    }
};


//my code, binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size()) {
            return -1;
        }
        
        int begin = 0;
        int end = nums.size() - 1;
        
        if(target > nums[end]) {
            return end + 1;
        }
        
        while(begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                end = mid;
                //return mid; // end = mid can be changed to end = mid
            } else if(nums[mid] > target) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        
        if(nums[begin] >= target) {    
            return begin;
        } else if(nums[end] >= target) {
            return end;
        } else {
            return -1;
        }
    }
}; 




int main(){
	return 0;
}