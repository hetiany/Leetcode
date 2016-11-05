//my code, using sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (0 + len) * (len + 1)/ 2;
        for(int i = 0; i < len; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};


//Find online, using bit
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};