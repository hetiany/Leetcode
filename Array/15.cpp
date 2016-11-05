#include <iostream>
#include <vector>
using namespace std;

//3sum
//Find online, two pointers
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
	    if(nums.size() <=2) return {};
	    vector<vector<int> > rtn;
	    sort(nums.begin(), nums.end());

	    for(int i =0; i < nums.size()-2;) {
	        int start = i + 1, end = nums.size() - 1;

	        while(start < end){
	            if(nums[i]+nums[start]+nums[end] == 0){
	                rtn.push_back({nums[i],nums[start],nums[end]});
	                start++;
	                end--;
	                while((start < end) && nums[start] == nums[start-1]) {
	                	start++;
	                }
	                while((start < end) && nums[end] == nums[end+1]) {
	                	end--;
	                }

	            } else if(nums[i]+nums[start]+nums[end] < 0) {
	                start++;
	                while((start < end) && nums[start] == nums[start-1]) {
	                	start++;
	                }
	            } else {
	                end--;
	                while((start < end) && nums[end] == nums[end+1]) {
	                	end--;
	                }
	            }
	        }

	        i++;
	        while((i < nums.size()-2) && nums[i] == nums[i-1]) {
	            i++;
	        }
	    }
	    return rtn;
    }
};


//My code, changed from online answer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            int second = i + 1;
            int third = nums.size() - 1;
            while(second < third) {
                int cursum = nums[i] + nums[second] + nums[third];
                if(cursum == 0) {
                    result.push_back({nums[i], nums[second], nums[third]});
                    ++second;
                    --third;
                    while( (second < third) && nums[second] ==  nums[second-1]) {
                        ++second;
                    }
                    while( (second < third) && nums[third] ==  nums[third+1]) {
                        --third;
                    }
                } else if(cursum < 0) {
                    ++second;
                    /*below sentance can be added or not*/
                    /*while( (second < third) && nums[second] ==  nums[second-1]) {
                        ++second;
                    }*/
                } else {
                    --third;
                    /*below sentance can be added or not*/
                    /*while( (second < third) && nums[third] ==  nums[third+1]) {
                        --third;
                    }*/
                }
            }
            while( (nums[i] == nums[i+1]) && (i + 1 < nums.size() - 2) ) {
                ++i;
            }
        }
        return result;
    }
};

//my code, 09/02/2016
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> record;
        if(nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int start, left, right, target; 
        for(int i = 0; i < nums.size() - 2;) {
            target = -nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    record = {nums[i], nums[left], nums[right]};
                    result.push_back(record);
                    //result.push_back({nums[start], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(nums[left] == nums[left - 1] && left < right) {
                        ++left;
                    }
                    while(nums[right] == nums[right + 1] && left < right) {
                        --right;
                    }
                } else if(nums[left] + nums[right] > target) {
                    --right;
                } else {
                    ++left;
                }
            }
            ++i;
            while(nums[i] == nums[i - 1] && i < nums.size() - 2) {
                ++i;
            }
        }
        return result;
    }
};

// my code, 09/25/2016
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2;) {
            int second = i + 1, third = nums.size() - 1;
            while(second < third) {
                if(nums[i] + nums[second] + nums[third] == 0) {
                    res.push_back({nums[i], nums[second], nums[third]});
                    while(nums[second] == nums[second + 1] && second + 1 < third) {
                        ++second;
                    }
                    ++second;
                    while(nums[third] == nums[third - 1] && second < third - 1) {
                        --third;
                    }
                    --third;
                } else if(nums[i] + nums[second] + nums[third] > 0) {
                    --third;
                } else {
                    ++second;
                }
            }
            ++i;
            while(nums[i] == nums[i - 1]) {
                ++i;
            }
        }
        return res;
    }
};


int main() {
	return 0;
}