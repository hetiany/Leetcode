//my code, 11/14/2016
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) {
            return 0;
        }
        vector<int> dp(prices.size(), 0);
        dp[0] = prices[0];
        int maxPro = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] <= dp[i - 1]) {
                dp[i] = prices[i];
            } else {
                dp[i] = dp[i - 1];
            }
            maxPro = max(maxPro, prices[i] - dp[i]);
        }
        
        return maxPro;
    }
    
};

//Find online
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % n );
        reverse(nums.begin() + k % n , nums.end());
    }
};