#include <vector>
using namespace std;
 
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        this -> n = num.size();
        if(this -> n <= 1){
            (this -> vec).push_back(num);
            return this -> vec;
        }
        getPermutations(num, 0);
        return this -> vec;
    }
private:
    vector<vector<int> > vec;
    int n;
    void getPermutations(vector<int> &num, int i){
        if(i == n){
            vec.push_back(num);
            return;
        }
        for(int j = i; j < n; ++j){
            swap(num[i], num[j]);
            getPermutations(num, i + 1);
            swap(num[j], num[i]);
        }
    }
};
 
void print2DVector(vector<vector<int> > v){
    vector<vector<int> >::iterator itr1;
    for(itr1 = v.begin(); itr1 != v.end(); ++itr1){
        vector<int>::iterator itr2;
        for(itr2 = itr1 -> begin(); itr2 != itr1 -> end(); ++itr2)
            cout << *itr2 << " ";
        cout << endl;
    }
}
 
int main(int argc, char const *argv[])
{
    vector<int> numbers = {0, 1, 2, 3};
    vector<vector<int> > v;
    Solution sol;
    v = sol.permute(numbers);
    print2DVector(v);
    return 0;
}