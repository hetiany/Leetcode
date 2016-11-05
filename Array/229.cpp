//229. Majority Element II
//Find online
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, a = 0, b = 1; 
        for(auto n: nums){
            if (a == n){
                cnt1++;
            } else if (b == n){
                cnt2++;
            } else if (cnt1 == 0){
                a = n;
                cnt1 = 1;
            } else if (cnt2 == 0){
                b = n;
                cnt2 = 1;
            } else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(auto n: nums){
            if (n == a) {
                cnt1++;
            } else if (n == b) {
                cnt2++;
            }  
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3) {
            res.push_back(a);
        }   
        if (cnt2 > nums.size() / 3) {
            res.push_back(b);
        }  
        return res;
    }
};


//my code, 06/17/2016
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) {
            return result;
        }
        int first = 0, second = 1, f_count = 0, s_count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(first == nums[i]) {
                ++f_count;
            } else if(second == nums[i]) {
                ++s_count;
            } else if(f_count == 0) {
                ++f_count;
                first = nums[i];
            } else if(s_count == 0) {
                ++s_count;
                second = nums[i];
            } else {
                --f_count;
                --s_count;
            }
        }
        f_count = 0, s_count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == first) {
                ++f_count;
            }
            if(nums[i] == second) {
                ++s_count;
            }
        }
        if(f_count > nums.size() / 3) {
            result.push_back(first);
        }
        if(s_count > nums.size() / 3) {
            result.push_back(second);
        }
        return result;
    }
};




//my code, 06/17/2016
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) {
            return result;
        }
        if(nums.size() == 1) {
            result.push_back(nums[0]);
            return result;
        }
        if(nums.size() == 2 && nums[0] == nums[1]) {
            result.push_back(nums[0]);
            return result;
        }
         if(nums.size() == 2 && nums[0] != nums[1]) {
             result.push_back(nums[0]);
             result.push_back(nums[1]);
             return result;
         }
        
        int first = nums[0], second = nums[1], f_count = 1, s_count = 1;
        for(int i = 2; i < nums.size(); ++i) {
            if(f_count == 0) {
                ++f_count;
                first = nums[i];
            } else if(s_count == 0) {
                ++s_count;
                second = nums[i];
            } else if(nums[i] == first) {
                ++f_count;
            } else if(nums[i] == second) {
                ++s_count;
            } else {
                if(first != second) {
                    --f_count;
                    --s_count;
                } else {
                    --s_count;
                }
                
            }
        }
        f_count = 0, s_count = 0;
        if(first != second) {
            for(int i = 0; i < nums.size(); ++i) {
            if(first == nums[i]) {
                ++f_count;
            }
            if(second == nums[i]) {
                ++s_count;
            }
            }
            if(f_count > nums.size() / 3) {
                result.push_back(first);
            }
            if(s_count > nums.size() / 3) {
                result.push_back(second);
            }
            return result;
        } else {
            result.push_back(first);
            return result;
        }
    }
}; 