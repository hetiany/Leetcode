#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Time: O(n*2^n)   Space:

class Solution{
public:
    vector<vector<int> > subsets(vector<int>& nums){
    	sort(nums.begin(), nums.end());
    	vector<vector<int> > sets;
    	vector<int> set;
    	genSubsets(nums, 0, set, sets);
    	return sets;
    }
    	
    void genSubsets(vector<int>& nums, int start, vector<int>& set, vector<vector<int> >& sets) {
    	sets.push_back(set);
    	for(int i = start; i < nums.size(); ++i){
            if(i != start && nums[i] == nums[i-1]){
                continue;
            }
    		set.push_back(nums[i]);
    		genSubsets(nums, i+1 , set, sets);
    		set.pop_back();
    	}
    }
};


int main(){
	return 0;
}