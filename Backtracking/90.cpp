#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//Time: O(n*2^n)   Space:

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > subs;
        vector<int> sub;  
        gensubsetsWithDup(nums, 0, sub, subs);
        return subs;
    }

     void gensubsetsWithDup(vector<int>& nums, int start, vector<int>& sub, vector<vector<int> >& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
        	if( i == start || nums[i] != nums[i-1] ){
        		sub.push_back(nums[i]);
            	gensubsetsWithDup(nums, i + 1, sub, subs);
           		sub.pop_back();
        	}           
        }
    }
};


//my code, 05/23/2016
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> temp;
        int pos = 0;
        get_result(result, temp, pos, nums);
        return result;
    }
    void get_result(vector<vector<int> >& result, vector<int> temp, int pos, vector<int> nums) {
         if(nums.empty()) {
            return ;
        }
        result.push_back(temp);
        for(int i = pos; i < nums.size(); ++i) {
            if(i != pos && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            get_result(result, temp, i + 1, nums);
            temp.pop_back();
        }
    }
};


int main(){
	return 0;
}