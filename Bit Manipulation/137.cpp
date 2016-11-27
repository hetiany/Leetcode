#include <vector>
#include <algorithm>
//#include <unordered_map>
#include <iostream>
using namespace std;

//Single Number II, find online, time O(n), space O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
	    int count[32] = {0};
	    int result = 0;
	    for (int i = 0; i < 32; i++) {
	        for (int j = 0; j < nums.size(); j++) {
	            if ((nums[j] >> i) & 1) {
	                count[i]++;
	            }
	        }
	        result |= ((count[i] % 3) << i);
	    }
	    return result;
	}
};


//find online, updated, cannot understand
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
         
        for (int i = 0; i < nums.size(); i++){
            t1 = t1 ^ nums[i];
            t2 = t2 | ((t1^nums[i]) & nums[i]);
            t3 = ~(t1 & t2);
            t1 = t1 & t3;
            t2 = t2 & t3;
        }
         
        return t1;
    }
};


//Find online, cannot understand
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
     	for (auto c : nums)
     	{
     		int tmp = (a & ~b & ~c) | (~a & b &c);
     		b = (~a & b & ~c) | (~a & ~b &c);
     		a = tmp;
     	}
     	return a | b;
    }
};


//my code, 07/16/2016
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
	    int result = 0;
	    for (int i = 0; i < 32; i++) {
	        for (int j = 0; j < nums.size(); j++) {
	            count[i] += (nums[j] >> i) & 1;
	        }
	        result += ((count[i] % 3) << i);
	    }
	    return result;
    }
};


//my code, 11/14/2016
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int record = 0;
        for(int i = 0; i < 32; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                record += nums[j] >> i & 1;
            }
            int temp;
            temp = record % 3 << i;
            res += temp;
            record = 0;
        }
        return res;
    }
};


int main(){
	int i = 10;
	//int n = ~i;
	cout << (i >>1) << endl;
	//cout << n << endl;
	return 0;
}