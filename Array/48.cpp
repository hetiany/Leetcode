#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Rotate Image
//Liu
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//my code, 10/12/2016, runtime error
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > res(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; i < n; ++j) {
                res[j][n - 1 - i] = matrix[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                matrix[i][j] = res[i][j];
            }
        }
    }
};

//my code, 10/12/2016, in place
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > res(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n - 1 - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        
    }
};



int main(){
	return 0;
}