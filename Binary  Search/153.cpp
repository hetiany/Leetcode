#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//153. Find Minimum in Rotated Sorted Array
//my code, 06/08/2016, can be accepted but not correct, not binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


//Find online
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] < nums[end])
                return nums[start];

            int mid = (start+end)/2;

            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};


//my code, 06/09/2016, find the first position > last num
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int target = nums[nums.size() - 1];
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] > target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        if(nums[begin] > nums[end]) {
            return nums[end];
        } else {
            return nums[begin];
        }
    }
};


//my code, 06/09/2016, compare the last num every time
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] > nums[end]) {
                begin = mid;       
            } else {
                end = mid;
            }
        }
        if(nums[begin] > nums[end]) {
            return nums[end];
        } else {
            return nums[begin];
        }
    }
};


int main() {
	return 0;
}