//Search Insert Position
//my code, 06/05/2016
//Time: O(log(N)), Space: O(1), first position >= target
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                return mid;
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
            return end + 1;
        }
    }
};


//my code, another version
//Time: O(log(N)), Space: O(1), last position < target + 1, "+1" means index plus 1,
//                                                           not value of target plus 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        
        if(nums[end] < target) {
            return end + 1;
        } else if(nums[begin] < target) {
            return begin + 1;
        } else {
            return begin;
        }
    }
};