#include <iostream>
#include <vector>
using namespace std;


//Merge Sorted Array. run time error
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         std::vector<int>:: iterator itr1 = nums1.begin();
        std::vector<int>:: iterator itr2 = nums2.begin();

        while( itr1 != nums1.end() && itr2 != nums2.end() ) {
          if(*itr1 < *itr2){
              if( (itr1 + 1) != nums1.end() ) {
                 ++itr1; 
              } else {
                  ++itr1;
                  nums1.insert(itr1, *itr2);
                  ++itr2;
                  ++itr1;
              }
          }else{
            itr1 = nums1.insert(itr1,*itr2);
            ++itr2;
            ++itr1;
          }
        }
        if(itr1 == nums1.end() && itr2 != nums2.end()){
          while(itr2 != nums2.end()){
            itr1 = nums1.insert(itr1, *itr2);
            ++itr2;
            ++itr1;
          }
        }
    }
};



//Find online
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int k = m+n-1;  
       int i, j;  
       for(i = m - 1, j = n - 1; i >= 0 && j >= 0; k--) {  
           if(nums1[i] >= nums2[j]) {  
               nums1[k] = nums1[i];  
               i--;  
           } else {
               nums1[k] = nums2[j];  
               j--; 
           }
      }  
      while(j >= 0) {  
          nums1[k] = nums2[j];  
          k--; 
          j--;  
      }
    }
};

int main(){
	return 0;
}