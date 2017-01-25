//my code, 1/22/2017
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        int last = 1, flag = 0;
        for(int cur = 1; cur < nums.size(); ++cur) {
            if(nums[cur] != nums[cur - 1]) {
                flag = 0;
                nums[last] = nums[cur];
                ++last;
            } else {
                if(flag == 0) {
                    flag = 1;
                    nums[last] = nums[cur];
                    last++;
                } 
            }
        }
        return last;
    }
};

//find online
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};