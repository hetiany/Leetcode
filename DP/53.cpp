//Lei, DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (sum < 0) {
                sum = 0;
            }// -2, 1
            sum += nums[i];
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};

//my code, 10/29/2016, changed by Lei DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        int maxSum = nums[0];
        int curSum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(curSum < 0) {
                curSum = 0;
            }
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
        
    }
};

//my code, 10/29/2016
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(dp[i - 1] < 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i- 1] + nums[i];
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};


//Lei, divide and conquer, I can't understand this thought ???
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return subSum(nums, 0, nums.size() - 1);
    }
    int subSum(vector<int>& nums, int left, int right) {
        if (left > right) return 0;
        if (left == right) return nums[left];
        int m = left + ((right - left) >> 1);
        int leftSum = subSum(nums, left, m);
        int rightSum = subSum(nums, m + 1, right);

        int sum = 0, middleLeft = INT_MIN, middleRight = INT_MIN; 
        for(int i = m; i >= left ; --i) {
            sum += nums[i];
            middleLeft = max(middleLeft, sum);
        }

        for(int i = m + 1, sum = 0; i <= right; ++i) {
            sum += nums[i];
            middleRight = max(middleRight, sum);
        }
        return max(max(leftSum, rightSum), middleRight + middleLeft);
    }
};


//my code, divide and conquer, 11/14/2016
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }    
        return maxSubSum(nums, 0, nums.size() - 1);
    }
    int maxSubSum(vector<int>& nums, int left, int right) {
        if(left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int sumLeft = maxSubSum(nums, left, mid);
        int sumRight = maxSubSum(nums, mid + 1, right);
        
        int sum = 0, midLeft = INT_MIN, midRight = INT_MIN;
        for(int i = mid; i >= left; --i) {
            sum += nums[i];
            midLeft = max(midLeft, sum);
        }
        sum = 0;
        for(int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            midRight = max(midRight, sum);
        }
        return max(max(sumLeft, sumRight), midLeft + midRight);
    }
};



