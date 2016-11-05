//Lei, DFS, time limit exceed
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

//Lei
class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        //fill(dp, dp + n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//Lei
class Solution {
public:
    int climbStairs(int n) {
        int dp[n];
        //fill(dp, dp + n + 1, 0);
        dp[0] = 1, dp[1] = 2;
        for(int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};


//jiuzhang
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) {
            return 1;
        }
        int last = 1, lastlast = 1, now = 0;
        for(int i = 2; i <= n; ++i) {
            now = last + lastlast;
            lastlast = last;
            last = now;
        }
        return now;
    }
};