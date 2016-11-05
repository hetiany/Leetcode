#include <iostream>
using namespace std;
 
/*class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0){
            A = NULL;
            return 0;
        }

        int tail = n-1;

        for(int i = 0; i < n; ++i){
            while(A[tail] == elem){
                A[tail] = '\0';
                tail--;
            }

            if(A[tail] == elem){
                A[tail] = '\0';
                tail--;

            }

            if(A[i] == elem){
                if(tail > i) A[i] = A[tail--];
            }
        }

        return ++tail;
    }
};
*/

// leetcode pdf
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for(int i=0; i<n; ++i){
            if(A[i] != elem){
                A[index++] = A[i];
            }
        }
        return index;
    }
};
 
int main(int argc, char const *argv[])
{
    int A[6] = {1,3,4,2,1,1};
    Solution sol;
    cout << sol.removeElement(A, 6, 1) << "\n" << endl;
    int idx = 0;
    while(A[idx]) cout << A[idx++] << endl;
    return 0;
}