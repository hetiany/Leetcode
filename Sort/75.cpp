#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;



//Sort Colors
//Find online
/*class Solution {
public:
    void sortColors(vector<int>& nums) {
    	   int red=0, white =0, blue=0;   
            for(int i =0; i < nums.size(); i++)   
            {   
                 switch(nums[i])   
                 {   
                 case 0:   
                      red++;break;   
                 case 1:    
                      white++;break;   
                 case 2:   
                      blue++;break;   
                 }   
            }   
            for(int i =0; i<nums.size(); i++)   
            {   
                 if(red>0)   
                 {   
                      nums[i]=0;   
                      red--;   
                      continue;   
                 }   
                 if(white>0)   
                 {   
                      nums[i] =1;   
                      white--;   
                      continue;   
                 }   
                 nums[i]=2;   
            } 
        
    }
};*/

//Liu, good method
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroBegin = -1, i = 0, twoEnd = nums.size();
        while(i < twoEnd){
            if(nums[i] == 0 && i != ++zeroBegin)
                swap(nums[zeroBegin], nums[i]);
            else if(nums[i] == 2 && i != --twoEnd)
                swap(nums[twoEnd], nums[i]);
            else ++i;
        }
    }
};




int main(){
	return 0;
}