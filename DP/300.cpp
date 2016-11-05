//jiuzhang
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sum = nums.size();
        vector<int> f(sum, 1);
        for (int i = 0; i < sum; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < sum; ++i) {
            res = max(res, f[i]);
        }
        return res;
    }
};


//Lei
class Solution {
public:
   int lengthOfLIS(vector<int>& nums) 
 {
    int n = nums.size();
    if (n == 0) return 0;
    //int dp[n] = {1};
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max (maxLen, dp[i]);
                }
            }   
    }
    return maxLen;
 }
};