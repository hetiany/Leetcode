#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
 
void print2DVector(vector<vector<int> > v){
    vector<vector<int> >::iterator itr1;
    for(itr1 = v.begin(); itr1 != v.end(); ++itr1){
        vector<int>::iterator itr2;
        for(itr2 = itr1 -> begin(); itr2 != itr1 -> end(); ++itr2)
            cout << *itr2 << "\t";
        cout << endl;
    }
}
 
int main(int argc, char const *argv[])
{
    vector<vector<int> > v = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };
    print2DVector(v);
    cout << endl;
    Solution sol;
    sol.rotate(v);
    print2DVector(v);
    return 0;
}