#include <iostream>
using namespace std;
 
class Solution {
public:
    void sortColors(int A[], int n) {
        int zeroBegin = -1, i = 0, twoEnd = n;
        while(i < twoEnd){
            if(A[i] == 0 && i != ++zeroBegin)
                swap(A[zeroBegin], A[i]);
            else if(A[i] == 2 && i != --twoEnd)
                swap(A[twoEnd], A[i]);
            else ++i;
        }
    }
};
 
int main(int argc, char const *argv[])
{
    int A[] = {1, 0, 2, 0, 1, 1, 2};
    for(int i = 0; i < 7; ++i)
        cout << A[i] << " ";
    cout << endl;
 
    Solution sol;
    sol.sortColors(A, 7);
 
    for(int i = 0; i < 7; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}