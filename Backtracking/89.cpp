#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


//Gray Code
//Find online, bit manipulation, space complexity: O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);        
        for (int i = 0; i < n; i++) {
            int curCount = result.size();
            // push back all element in result in reverse order
            while (curCount) {
                curCount--;
                int curNum = result[curCount];
                curNum += (1 << i);
                result.push_back(curNum);
            } 
        }
        return result;
    }
};


//Find online, bit manipulation
class Solution {
public:
    vector<int> grayCode(int n) {
        int N(1 << n), tmp;
        vector<int> result;
        for(int i(0); i < N; i++)
        {
            tmp = i << 1;
            result.push_back((tmp ^ i) >> 1);
        }
        return result;
    }
};



int main() {
	return 0;
}