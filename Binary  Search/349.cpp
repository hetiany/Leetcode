#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//Find online, using set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};


//similar to above
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m;
        for(int i = 0; i < nums1.size(); ++i) {
            m.insert(nums1[i]);
        }
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};


//also similar
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m;
        
        for(vector<int>:: iterator ptr = nums1.begin(); ptr != nums1.end(); ++ptr) {
            m.insert(*ptr);
        }
        vector<int> res;
        for (vector<int>:: iterator ptr = nums2.begin(); ptr != nums2.end(); ++ptr)
            if (m.find(*ptr) != m.end()) {
                res.push_back(*ptr);
                m.erase(*ptr);
            }
        return res;
    }
};


//my code, using two pointer
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                if(!result.size() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
            
        }
        return result;
    }
};


int main() {
	Solution sol;
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);


	vector<int> vec2;
	vec2.push_back(2);
	vec2.push_back(2);
	vec2.push_back(4);
	vec2.push_back(3);

	vector<int> result = sol.intersection(vec1, vec2);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	return 0;
}