//Find online
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};


//my code, 06/20/2016
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); ++i) {
            min_price = min(prices[i], min_price);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};


//my code, 10/17/2016
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int curLowest = INT_MAX;
        for(int i = 0; i < prices.size(); ++i) {
            curLowest = min(prices[i], curLowest);
            maxPro = max(maxPro, prices[i] - curLowest);
        }
        return maxPro;
    }
}; 


//my code, 11/14/2017
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