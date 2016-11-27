//Lei
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
     	if (n <= 1) return;
     	int j = n - 1;
     	while (j > 0 && nums[j - 1] >= nums[j]) {
     	   j--; 
     	}
     	if (j == 0) {
     	    reverse (nums.begin(), nums.end());
     	}
     	else {
     	    //cout<<j;
     		int p;
     		for (p = n - 1; p >= j; --p) {
     		    if (nums[p] > nums[j - 1]) {
     		        break;
     		    }
     		}
     		swap(nums[p],nums[j - 1]);
     		reverse(nums.begin() + j, nums.end());
     	}
    }
};