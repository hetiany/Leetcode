#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


//3Sum Closest
//Find online
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());

    int closest = nums[0]+nums[1]+nums[2];

    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) {
        	continue;
        }
        int second = first + 1;
        int third = nums.size() - 1;            
        while(second < third) {
            int curSum = nums[first] + nums[second] + nums[third];
            if(curSum == target) {
            	return curSum;
            }
            if(abs(target-curSum) < abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
                /*below sentance can be added or not*/
                /*while(second < third && nums[third] == nums[third+1]) {
                	--third;
                }*/
            } else {
                ++second;
               /*below sentance can be added or not*/
               /* while(second < third && nums[second] == nums[second-1]) {
                	++second;
                }*/
            }
        }
    }
    return closest;
    }
};


//my code, 09/02/2016
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(int first = 0; first < nums.size() -2;) {
            int second = first + 1;
            int third = nums.size() - 1;   
            while(second < third) {
                int curSum = nums[first] + nums[second] + nums[third];
                if(curSum == target) {
                    return curSum;
                } else if(curSum > target) {
                    --third;
                    /*while(second < third && nums[third] == nums[third+1]) {
                        --third;
                    }*/
                } else {
                    ++second;
                    /*while(second < third && nums[second] == nums[second-1]) {
                        ++second;
                    }*/
                }
                if(abs(target - curSum) < abs(target - closest)) {
                    closest = curSum;
                }
            }
            ++first;
            while(first < nums.size() - 2 && nums[first] == nums[first - 1]) {
                ++first;
            }
        }
        return closest;
    }
};

//my code, 09/25/2016
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int total = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2;) {
            int second = i + 1, third = nums.size() - 1;
            while(second < third) {
                int curSum = nums[i] + nums[second] + nums[third];
                if(curSum == target) {
                    return curSum;
                } else if(curSum > target) {
                    if(abs(total - target) > abs(curSum - target)) {
                        total = curSum;
                    }
                    --third;
                } else {
                    if(abs(total - target) > abs(curSum - target)) {
                        total = curSum;
                    }
                    ++second;
                }
            }
            ++i;
            while(nums[i] == nums[i - 1] && i < nums.size() - 2) {
                ++i;
            }
        }
        return total;
    }
};


//Find online
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    vector<int> v(nums.begin(), nums.end()); // I didn't wanted to disturb original array.
    int n = 0;
    int ans = 0;
    int sum;

    sort(v.begin(), v.end());

    // If less then 3 elements then return their sum
    while (v.size() <= 3) {
        return accumulate(v.begin(), v.end(), 0);
    }

    n = v.size();

    /* v[0] v[1] v[2] ... v[i] .... v[j] ... v[k] ... v[n-2] v[n-1]
     *                    v[i]  <=  v[j]  <= v[k] always, because we sorted our array. 
     * Now, for each number, v[i] : we look for pairs v[j] & v[k] such that 
     * absolute value of (target - (v[i] + v[j] + v[k]) is minimised.
     * if the sum of the triplet is greater then the target it implies
     * we need to reduce our sum, so we do K = K - 1, that is we reduce
     * our sum by taking a smaller number.
     * Simillarly if sum of the triplet is less then the target then we
     * increase out sum by taking a larger number, i.e. J = J + 1.
     */
    ans = v[0] + v[1] + v[2];
    for (int i = 0; i < n-2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            sum = v[i] + v[j] + v[k];
            if (abs(target - ans) > abs(target - sum)) {
                ans = sum;
                if (ans == target) return ans;
            }
            (sum > target) ? k-- : j++;
        }
    }
    return ans;
    }
};

int main() {
	return 0;
}