//my code, 06/24/2016
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = nums.size();
        vector<int> store_1(count, 1);
        vector<int> store_2(count, 1);
        int temp = 1;
        for(int i = 1; i < count; ++i) {
            temp *= nums[i - 1];
            store_1[i] = temp;
        }
        temp = 1;
        for(int i = count - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            store_2[i] = temp;
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] = store_1[i] * store_2[i];
        }
        return nums;
    }
};


//Lei, fellow up, Space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int length = nums.size();
        int zeroCount = 0, res = 1;
        for (int i = 0; i < length; ++i) {
            if (nums[i] == 0) zeroCount++;
            res *= nums[i];
        }
        if (zeroCount >= 2) return vector<int>(length,0);
        else if (res == 0) {
            int pos = 0, res = 1;
            for (int i = 0; i < length; ++i) {
                if (nums[i] != 0) {
                    res *= nums[i];
                    nums[i] = 0;
                } else {
                  pos = i;  
                }
            }
            nums[pos] = res;
        } else {
             for (int i = 0; i < length; ++i) {
                nums[i] = res / nums[i]; 
             }
        }
        return nums;
    }
};