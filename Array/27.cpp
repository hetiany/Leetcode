#include <iostream>
#include <vector>
//#include <cstdio>

using namespace std;



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int length = nums.size();
    	if (length == 0){
            return 0;
    	}

        std::vector<int>::iterator itr = nums.begin();
        while(itr != nums.end()){
        	if((*itr) == val){
                itr = nums.erase(itr);  
                --length; 
            }
            else ++itr;
        }
        return length;
    }
};



int main(){
    std::vector<int> A;
    //A.reserve(8);
    A.push_back(1);
   /* A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);*/
    Solution sol;
    cout << sol.removeElement(A,1) << endl;
    int idx = 0;
    while(A[idx]) cout << A[idx++] << endl;
  
	return 0;
}

