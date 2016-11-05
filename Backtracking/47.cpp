#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//Find online
//Permutations II
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        recursion(nums, 0, res);
        return res;
    }

    // vector<int> nums cannot be changed to vector<int>& nums, but in Q46 can be changed
    void recursion(vector<int> nums, int i, vector<vector<int> > &res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            if (i != k && nums[i] == nums[k]) {
                continue;
            }
            swap(nums[i], nums[k]);
            recursion(nums, i+1, res);
        }
    }
};



//my code, 05/24/2016
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        recursion(nums, 0, res);
        return res;
    }

    // vector<int> nums cannot be changed to vector<int>& nums, but in Q46 can be changed
    void recursion(vector<int> nums, int begin, vector<vector<int> > &res) {
        if (begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            if (begin != i && nums[begin] == nums[i]) {
                continue;
            }
            swap(nums[i], nums[begin]);
            recursion(nums, begin+1, res);
        }
    }
};

int main(){
	return 0;
}