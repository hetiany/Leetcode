//using DP, time limit exceed
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(!nums.size()) {
            return false;
        }
        int sum = nums.size();
        vector<bool> record(sum, false);
        record[0] = true;
        
        for(int i = 1; i < sum; ++i) {
            for(int j = 0; j < i; ++j) {
                if(record[j] && j + nums[j] >= i) {
                    record[i] = true;
                    break;
                }
            }
        }
        return record[sum - 1];
    }
};


//using greedy, jiuzhang, ?????
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(!nums.size()) {
            return false;
        }
        int farthest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i <= farthest && nums[i] + i >= farthest) {
                farthest = nums[i] + i;
            }
        }
        return farthest >= nums.size() - 1;   
    }
};