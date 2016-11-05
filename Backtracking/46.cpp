#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


//Liu
//Permutations
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        n = nums.size();
        if(n <= 1){
            vec.push_back(nums);
            return vec;
        }
        getPermutations(nums, 0);
        return vec;
    }
private:
    vector<vector<int> > vec;
    int n;
    void getPermutations(vector<int> &nums, int i){
        if(i == n){
            vec.push_back(nums);
            return;
        }
        for(int j = i; j < n; ++j){
            swap(nums[i], nums[j]);
            getPermutations(nums, i + 1);
            swap(nums[j], nums[i]);
        }
    }
};



//Find online
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        sort( nums.begin(), nums.end() );
        vector<vector<int> > result;
        permuteRecursive(nums, 0, result);
        return result;
    }

    // permute nums[begin..end]
    // invariant: nums[0..begin-1] have been fixed/permuted
    // vector<int> nums can be changed to vector<int>& nums 
    void permuteRecursive(vector<int> nums, int begin, vector<vector<int> > &result)    {
        if ( begin == nums.size() ) {
            // one permutation instance
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            permuteRecursive(nums, begin + 1, result);
            // reset
            //swap(nums[begin], nums[i]);
        }
    }
};


//vector<int>& nums, there are two swap();
123
132

123--- base 123
213
231---

123--- base 123

321         312
312         321

//vector<int> nums, there is only one swap()
123
132

213 --- base 123
231

312 --- base 213
321


int main(){
	return 0;
}
