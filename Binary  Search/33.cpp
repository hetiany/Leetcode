#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//Search in Rotated Sorted Array 
//my code, 06/09/2016, can be accepted, but not accept, becourse time space is O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};


//my code, 06/10/2016, time: O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > nums[begin]) {
                if(target < nums[mid] && target >= nums[begin]) {
                   end = mid;
                } else {
                   begin = mid; 
                }
            }
            if(nums[mid] < nums[begin]) {
               if(nums[mid] < target && nums[end] >= target) {
                  begin = mid;
               } else {
                   end = mid;
               }
            }
        }
        if(nums[begin] == target) {
            return begin;
        } else if(nums[end] == target) {
            return end;
        } else {
            return -1;
        }
    }
};


//my code, 06/17/2016
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] >= nums[begin]) {
                if(nums[mid] == target) {
                    return mid;
                } else if( nums[mid] > target && target >= nums[begin]) {
                    end = mid;
                } else {
                    begin = mid;
                }
            }
            if(nums[mid] <= nums[end]) {
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target && target <= nums[end]) {
                    begin = mid;
                } else {
                    end = mid;
                }
            }
        }
        if(nums[begin] == target) {
            return begin;
        } else if(nums[end] == target) {
            return end;
        } else {
            return -1;
        }
    }
};

int main() {
	return 0;
}