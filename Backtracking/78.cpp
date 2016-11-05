#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//Time: O(n*2^n)   Space:

//Subsets
//Find online, backtracking
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }

    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int> >& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};


//Find online, Bit manipulation
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        int elem_num = nums.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num);
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (nums[i]);
        return subset_set;
    }
};


//Find online, iterator
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 


//my code, 05/23/2016
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> temp;
        int pos = 0;
        get_result(result, temp, pos, nums);
        return result;
    }
    void get_result(vector<vector<int> >& result, vector<int> temp, int pos, vector<int>& nums) {
         if(nums.empty()) {
            return ;
        }
        result.push_back(temp);
        for(int i = pos; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            get_result(result, temp, i + 1, nums);
            temp.pop_back();
        }
    }
};


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	Solution sol;
	sol.subsets(a);
	return 0;
}