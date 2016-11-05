//Find online
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        //int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int diff = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            diff = diff ^ nums[i];
        }
        // Get its last set bit
        //This sentence is import for 
        //finding out an arbitrary set bit (for example, the rightmost set bit).
        diff &= -diff;
        // Pass 2 :
        vector<int> rets = {0, 0};      // this vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & diff) == 0) {        // the bit is not set
                rets[0] ^= num;
            }
            else {              // the bit is set
                rets[1] ^= num;
            }
        }
        return rets;
    }
};


//my code, 07/17/2016
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int diff = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            diff ^= nums[i];
        }
        diff = diff & (-diff);
        for(int i = 0; i < nums.size(); ++i) {
            if( (nums[i] & diff) == 0) {
                result[0] ^= nums[i];
            } else {
                result[1] ^= nums[i];
            }
        }
        return result;
        
    }
};