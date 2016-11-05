#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > vec;
        vector<int> tmp;
        for(int combination = (1 << k) - 1;
            combination <= (1 << n) - (1 << (n - k));
            combination = nextN(combination)){
            tmp.clear();
            int i = 0;
            while(i < n){
                if(combination & (1 << i))
                    tmp.push_back(i + 1);
                ++i;
            }
            vec.push_back(tmp);
        }
        return vec;
    }
private:
    int nextN(int n){
        int a = n & (-n);
        int b = n + a;
        int c = n ^ b;
        int d = c / a;
        int e = d >> 2;
        int f = b | e;
        return f;
    }
};
 
void printVector(vector<vector<int> > &v){
    vector<vector<int> >::iterator vitr;;
    for(vitr = v.begin(); vitr != v.end(); ++vitr){
        vector<int>::iterator itr;
        for(itr = vitr -> begin(); itr != vitr -> end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
}
 
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int> > v = sol.combine(6, 2);
    printVector(v);
 
    return 0;
}