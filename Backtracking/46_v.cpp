#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
		vector<vector<int> >permute(vector<int>& nums){
				vector<vector<int> > permute_nums;
				int begin = 0;
				get_permute(permute_nums, begin, nums);
				return permute_nums;
				
   	}
   		// vector<int> nums can be changed to vector<int>& nums
		void get_permute(vector<vector<int> >& permute_nums, int begin, vector<int> nums){
				if( begin == nums.size()){
						permute_nums.push_back(nums);
						return ; 
				}	
				
				for(int i = begin; i < nums.size(); i++){
						swap(nums[i], nums[begin]);
						get_permute(permute_nums, begin+1, nums);
						swap(nums[i], nums[begin]);
				}
		}
};


int main(){
	return 0;
}
