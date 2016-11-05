#include <iostream>
#include <vector>
using namespace std;


//4Sum
//Find online
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() < 4) {
        	return res;
        }
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size()-3; i++) {

            int target_3 = target - nums[i];

            for (int j = i + 1; j < nums.size()-2; j++) {
                int front = j + 1;
                int back = nums.size() - 1;

                while(front < back) {
                	int cur_target_3 = nums[j] + nums[front] + nums[back];
                    if (cur_target_3 < target_3) {
                    	front++;
                    	/*below sentance can be added or not*/
                    	/*while(front < back && nums[front] == nums[front-1]) {
                    		++front;
                    	}*/
                    }

                    else if (cur_target_3 > target_3) {
                    	back--;
                    	/*below sentance can be added or not*/
                    	/*while(front < back && nums[back] == nums[back+1]) {
                    		--back;
                    	}*/
                    } else {
                        vector<int> quadruplet(4);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);

                        ++front;
                        --back;

                        // Processing the duplicates of number 3
                        while (front < back && nums[front] == nums[front-1]) {
                        	++front;
                        }

                        // Processing the duplicates of number 4
                        while (front < back && nums[back] == nums[back+1]) {
                        	--back;
                        }
                    }
                }

                // Processing the duplicates of number 2
                while(j + 1 < nums.size() - 2 && nums[j + 1] == nums[j]) {
                	++j;
                }
            }

            // Processing the duplicates of number 1
            while (i + 1 < nums.size() - 3 && nums[i + 1] == nums[i]) {
            	++i;
            } 

        }

        return res;
    }
};



//my code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-3; ++i) {
            //int target_3 = target - nums[i];
            for(int j = i + 1; j < nums.size()-2; ++j) {
                int front = j + 1;
                int back = nums.size() - 1;
                while(front < back) {
                    int cur_target = nums[i] + nums[j] + nums[front] + nums[back];
                    if(cur_target == target) {
                       result.push_back({nums[i], nums[j], nums[front], nums[back]});
                        ++front;
                        --back;
                        while(front < back && nums[front] == nums[front-1]) {
                            ++front;
                        }
                        while(front < back && nums[back] == nums[back+1]) {
                            --back;
                        }
                    }  
                    if(cur_target < target) {
                        ++front;
                    } 
                    if(cur_target > target) {
                        --back;
                    }
                }
                while(nums[j] == nums[j+1] && j + 1 < nums.size()-2) {
                    ++j;
                }
            }
            while(nums[i] == nums[i+1] && i + 1 < nums.size()-3) {
                    ++i;
            }
        }
        return result;
    }
};

//my code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3;) {
            //int target_3 = target - nums[i];
            for(int j = i + 1; j < nums.size() - 2;) {
                int front = j + 1;
                int back = nums.size() - 1;
                while(front < back) {
                    int cur_target = nums[i] + nums[j] + nums[front] + nums[back];
                    if(cur_target == target) {
                       result.push_back({nums[i], nums[j], nums[front], nums[back]});
                        ++front;
                        --back;
                        while(front < back && nums[front] == nums[front-1]) {
                            ++front;
                        }
                        while(front < back && nums[back] == nums[back+1]) {
                            --back;
                        }
                    }  
                    if(cur_target < target) {
                        ++front;
                    } 
                    if(cur_target > target) {
                        --back;
                    }
                }
                ++j;
                while(nums[j] == nums[j - 1] && j < nums.size() - 2) {
                    ++j;
                }
            }
            ++i;
            while(nums[i] == nums[i - 1] && i < nums.size() - 3) {
                ++i;
            }
        }
        return result;
    }
};


int main() {
	return 0;
}