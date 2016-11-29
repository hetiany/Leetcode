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

//Binary Search, Java, Jiuzhang
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] minLast = new int[nums.length + 1];
        minLast[0] = Integer.MIN_VALUE;
        for (int i = 1; i <= nums.length; i++) {
            minLast[i] = Integer.MAX_VALUE;
        }
        
        for (int i = 0; i < nums.length; i++) {
            // find the first number in minLast > nums[i]
            int index = binarySearch(minLast, nums[i]);
            minLast[index] = nums[i];
        }
        
        for (int i = nums.length; i >= 1; i--) {
            if (minLast[i] != Integer.MAX_VALUE) {
                return i;
            }
        }
        
        return 0;
    }
    private int binarySearch(int[] minLast, int num) {
        int start = 0, end = minLast.length - 1;
        while (start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if (minLast[mid] >= num) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (minLast[start] >= num) {
            return start;
        }
        return end;
    }
}