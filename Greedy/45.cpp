//using DP, time limit exceed
class Solution {
public:
    int jump(vector<int>& nums) {
        int sum = nums.size();
        vector<int> steps(sum, INT_MAX);
        steps[0] = 0;
        for(int i = 1; i < sum; ++i) {
            for(int j = 0; j < i; ++j) {
                if(steps[j] != INT_MAX && j + nums[j] >= i) {
                    steps[i] = min(steps[i], steps[j] + 1);
                    break;
                }
            }
        }
        return steps[sum - 1];
    }
};

//my code, 11/28/2016
class Solution {
public:
    int jump(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        int n = nums.size();
        vector<int> record(n, INT_MAX);
        record[0] = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(record[j] != INT_MAX && nums[j] + j >= i) {
                    record[i] = min(record[i], record[j] + 1);
                }
            }
        }
        return record[n-1];
    } 
};


//using greedy, jiuzhang, ???????
class Solution {
public:
    int jump(vector<int>& nums) {
        if(!nums.size()) {
            return -1;
        }
        int start = 0, end = 0, jumps = 0;
        while (end < nums.size() - 1) {
            jumps++;
            int farthest = end;
            for (int i = start; i <= end; i++) {
                if (nums[i] + i > farthest) {
                    farthest = nums[i] + i;
                }
            }
            start = end + 1;
            end = farthest;
        }
        return jumps;
    }
};