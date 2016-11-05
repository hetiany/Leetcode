#include <iostream>
#include <vector>
using namespace std;


//First Bad Version
//my code, 06/07/2016
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(isBadVersion(mid)) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        if(isBadVersion(begin)) {
            return begin;
        } else if(isBadVersion(end)){
            return end;
        } else{
            return 0;
        }
    }
};

int main() {
	return 0;
}