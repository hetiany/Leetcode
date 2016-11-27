//my code, time limit exceeded, 11/21/2016
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        if(!nums.size()) {
            return 0;
        }
        int fast = 0, slow = 0, sum = 0, len = 0;
        while(fast < nums.size()) {
            while(nums[fast] < s) {
                sum += nums[fast];
                ++fast;
            }
            len = fast - slow;
            minLen = min(minLen, len);
            while(slow <= fast) {
                sum -= nums[slow];
                if(sum >= s) {
                    len = fast - slow;
                    minLen = min(minLen, len);
                    ++slow;
                } else {
                    break;
                }
            }
        }
        return minLen;
    }
};

//Lei
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, length = n + 1, start = 0, i = 0;
        for (i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum >= s) {
                while (sum >= s) {
                    length = min (length, i - start + 1);
                    sum -= nums[start++];
                }
            }
        }
        return length == n + 1 ? 0 : length; 
    }
};


//my code, 11/21/2016
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        if(!nums.size()) {
            return 0;
        }
        int fast = 0, slow = 0, sum = 0, len = 0;
        while(fast < nums.size()) {
            sum += nums[fast];
            if(sum >= s) {
                while(sum >= s) {
                    len = fast - slow + 1;
                    minLen = min(minLen, len);
                    sum -= nums[slow];
                    ++slow;
                }
            } 
            ++fast;
        }
        if(minLen == INT_MAX) {
            return 0;
        }
        return minLen;
    }
};


//my code, not correct ???
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        if(!nums.size()) {
            return 0;
        }
        int fast = 0, slow = 0, sum = 0, len = 0;
        while(fast < nums.size()) {
            while(sum < s) {
                sum += nums[fast];
                ++fast;
            }
            while(sum >= s) {
                len = fast - slow;
                minLen = min(minLen, len);
                sum -= nums[slow];
                ++slow;
            }
                
        }
        if(minLen == INT_MAX) {
            return 0;
        }
        return minLen;
    }
};