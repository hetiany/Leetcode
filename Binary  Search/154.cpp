#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//154. Find Minimum in Rotated Sorted Array II
//my code, 06/08/2016, can be accepted but not correct
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
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;

        while(lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else if (nums[mid] < nums[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return nums[lo];
    }
};


//my code, 06/09/2016, time space O(n)
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


int main() {
	return 0;
}