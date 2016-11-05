#include <iostream>
#include <vector>
using namespace std;

//Pascal's Triangle II
//Find online
class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};

int main(){
	return 0;
}