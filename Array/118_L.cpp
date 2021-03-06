#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        for (int i = 0; i < numRows; ++i)
        {
            insertIntoVec(i);
        }
        return v;
    }
    void insertIntoVec(int rowIdx) {
        temp.clear();
        temp.push_back(1);
        for (int i = 1; i < rowIdx; ++i){
            temp.push_back(v.back()[i - 1] + v.back()[i]);
        }
        if (rowIdx >= 1){
            temp.push_back(1);
        }
        v.push_back(temp);
    }
 
private:
    vector< vector<int> > v;
    vector<int> temp;
};
 
int main(int argc, char const *argv[])
{
    Solution sol;
    vector< vector<int> > vec;
    vec = sol.generate(1);
    cout << vec[0][0] << endl;
    return 0;
}