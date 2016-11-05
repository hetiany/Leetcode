#include <iostream>
#include <vector>
using namespace std;


//Althougn begin + 1 < end, but in this question begin and end will point to the same 
//positon after loop

//Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, mid;
        while(begin + 1 < end) {
            mid = (begin + end) / 2;
            if(nums[mid] < nums[mid + 1]) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }       
        if(nums[begin] < nums[end]) {
            return end;
        } else {
            return begin;
        }
    }
};



//Find online
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(nums[mid1] < nums[mid2])
                low = mid2;
            else
                high = mid1;
        }
        // can be return high
        return low;
    }
};


     int start = 1, end = nums.length-2; // 1.答案在之间，2.不会出界 
        while(start + 1 <  end) {
            int mid = (start + end) / 2;
            if(nums[mid] < nums[mid - 1]) {
                end = mid;
            } else if(nums[mid] < nums[mid + 1]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if(nums[start] < nums[end]) {
            return end;
        } else { 
            return start;
        }



int main() {
	return 0;
}