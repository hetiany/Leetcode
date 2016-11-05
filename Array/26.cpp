#include <iostream>
#include <vector>
using namespace std;

//Remove Duplicates from Sorted Array, O(n),O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
        return nums.size();

        int length=1;//长度
        
        vector<int>::iterator cur = nums.begin()+1;
        for(vector<int>::iterator itr = nums.begin()+1; itr != nums.end(); itr++){
            if(*itr != *(itr-1)){
                *cur = *itr;
                cur++;
                length++;
            }
        }
            return length;
        }
        
};


/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int tw = 1;
        int idx = 0;

    while(idx < nums.size()-1)
    {
        int tmp = idx + 1;

         while(tmp < nums.size() && nums[tmp] == nums[idx])
         {
             ++tmp;
             length--;
         }

    if(tmp < nums.size() && nums[tmp] != nums[idx])
       {
        nums[tw] = nums[tmp];
        tw++;
        idx = tmp;
     }
    else
        break;
}
return length;
        
    }
};*/
 
int main(int argc, char const *argv[])
{
    /*int A[8] = {1, 1, 2, 2, 2, 3, 2, 2};
    Solution sol;
    //cout << sol.removeDuplicates(A, 6) << endl;
    sol.removeDuplicates(A, 8);
    int idx = 0;
    while(A[idx]) cout << A[idx++] << endl;*/
    std::vector<int> A;
    A.reserve(8);
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    Solution sol;
    cout << sol.removeDuplicates(A) << endl;
    int idx = 0;
    while(A[idx]) cout << A[idx++] << endl;
    return 0;
}