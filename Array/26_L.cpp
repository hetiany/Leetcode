#include <iostream>
using namespace std;
 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            A = NULL;
            return 0;
        }
        int index = 1;
        for (int i = 1; i < n; ++i){
            if(A[i] != A[i-1])
                A[index++] = A[i];
        }
        A[index] = '\0';
        return index;
    }
    
};
 
int main(int argc, char const *argv[])
{
    int A[6] = {1, 1, 2, 2, 2, 3};
    Solution sol;
    cout << sol.removeDuplicates(A,6) << endl;
    //sol.removeDuplicates(A, 6);
    int idx = 0;
    while(A[idx]) cout << A[idx++] << endl;
    return 0;
}