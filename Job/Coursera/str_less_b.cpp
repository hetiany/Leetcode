
/* 给了一个数组（没排序的) d和一个long t，求有多少组（i,j,k)可以满足的d[i]<d[j]<d[k]且d[i]+d[j]+d[k]<=t
 
 {2, 3, 5, 7, 4, 2, 7}  v
 2222
 map<int, int> record;
  
 sort
 
 vector<pair<val, count>> vec;
 for() {
     i = 0;
        if(v[i] != v[i - 1] ) vec.push_back(make_pair(val, 0));
     vec.back().second++;
 }
 i =0 ,j= 1,k = n- 1; 
 
 {2，3，4} = 2*2*3;
 2 -> 2
 3 -> 2
 4 -> 3
 5 -> 1
 7 -> 2*/
 #include <iostream>
 #include <string>
 using namespace std;

 class Solution {
 public:
 	int get() {

 	}
 };

 int main() {

 	
 	return 0;
 }