#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
		vector<vector<int> >permute(vector<int>& nums){
				sort(nums.begin(), nums.end());
				vector<vector<int> > permute_nums;
				int begin = 0;
				get_permute(permute_nums, begin, nums);
				return permute_nums;
				
   	}
   		// vector<int> nums cannot be changed to vector<int>& nums, but in Q46 can be changed
		void get_permute(vector<vector<int> >& permute_nums, int begin, vector<int> nums){
				if( begin == nums.size() ){
						permute_nums.push_back(nums);
						return ; 
				}	
				
				for(int i = begin; i < nums.size(); i++){
						if( i != begin && nums[i] == nums[begin] ){
							continue;
						}
						swap(nums[i], nums[begin]);
						get_permute(permute_nums, begin+1, nums);
						//swap(nums[i], nums[begin]);
				}
		}
};


int main(){
	return 0;
}
