//Search for a Range
//Time: O(log(N)), Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int first_tar = 0;
        int last_tar = 0;
        if(!nums.size()) {
            return result;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while(begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                end = mid;    
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        
        if(nums[begin] == target) {
            first_tar = begin;
        } else if(nums[end] == target) {
            first_tar = end;
        } else {
            first_tar  = last_tar = -1;
        }
        
        begin = 0;
        end = nums.size() - 1;
        while(begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                begin = mid;    
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        
        if(nums[end] == target) {
            last_tar = end;
        } else if(nums[begin] == target) {
            last_tar = begin;
        } else {
            first_tar  = last_tar = -1;
        }
        
        if(first_tar != -1 && last_tar != -1) {
             result.push_back(first_tar);
             result.push_back(last_tar);
             return result;
        } else {
             result.push_back(-1);
             result.push_back(-1);
             return result;
        }
    }
};


//my code, 06/05/2016
//Time: O(log(N)), Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.empty()) {
            return result;
        }
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                end = mid;
            } else if (nums[mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        if(nums[begin] == target) {
            result[0] = begin;
        } else if(nums[end] == target) {
            result[0] = end;
        } else {
            result[0] = result[1] = -1;
            return result;
        }
        
        
        begin = 0, end = nums.size() - 1;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target) {
                begin = mid;
            } else if (nums[mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        
        if(nums[end] == target) {
            result[1] = end;
        } else if(nums[begin] == target) {
            result[1] = begin;
        } else {
            result[0] = result[1] = -1;
            return result;
        }
        return result;
        
    }
};