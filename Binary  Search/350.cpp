#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Intersection of Two Arrays II
//my code, using two pointers, 06/08/2016
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] > nums2[j]) {
                ++j;
            } else if(nums1[i] < nums2[j]) {
                ++i;
            } else {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return result;
    }
};



//Find online, using hash table
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            ++dict[nums1[i]];
        }
        for(int i = 0; i < nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) {
                res.push_back(nums2[i]);
            }
        return res;
    }
};


//my code, 06/08/2016, using hash table
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            if(dict.find(nums1[i]) == dict.end()) {
                dict[nums1[i]] = 1;
            } else{
                ++dict[nums1[i]];
            }
        }
        for(int i = 0; i < nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end()) {
                if(--dict[nums2[i]] >= 0) {
                    res.push_back(nums2[i]);
                }
            }
        return res;
    }
};


//my code, 06/17/2016
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            if(dict.find(nums1[i]) == dict.end()) {
                dict[nums1[i]] = 1;
            } else{
                ++dict[nums1[i]];
            }
        }
        for(int i = 0; i < nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end()) {
                res.push_back(nums2[i]);
                if(--dict[nums2[i]] == 0) {
                    dict.erase(nums2[i]);
                }
            }
        return res;
    }
};


int main() {
	return 0;
}
