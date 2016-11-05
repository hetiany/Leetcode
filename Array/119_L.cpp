#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        int n = rowIndex / 2 + 1;
        double x = 1;
        for (int i = 1; i < n; ++i){
            x = (double)(rowIndex - i + 1) * x / (double)i;
            v.push_back(x);
            //cout << v[i] << endl;
        }
 
        int idx;
        if (rowIndex % 2 == 1){
            idx = v.size() - 1;
        } else {
            idx = v.size() - 2;
        }
 
        for (int i = idx; i >= 0; i--){
            v.push_back(v[i]);
            //cout << v[i] << endl;
        }
        return v;
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<int> vec;
    vec = sol.getRow(11);
    cout << vec[0] << vec[1] << vec[2] << vec[3] << vec[4] << vec[5] << endl;
    return 0;
}