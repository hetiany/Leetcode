#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//Search in Rotated Sorted Array II
//my code, 06/09/2016, time space O(n)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return false;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
	return 0;
}