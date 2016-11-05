#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        vector<int>::reverse_iterator itr;
        digits.back()++;
        for(itr = digits.rbegin(); itr != digits.rend(); ++itr){
            //cout << *itr << endl;
            int tmp =  *itr + carry;
            carry = tmp / 10;
            *itr = tmp % 10;
        }
        if(carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};
 
void printVector(vector<int> &v){
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}
 
int main(int argc, char const *argv[])
{
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(9);
    vec.push_back(8);
    printVector(vec);
    Solution sol;
    vec = sol.plusOne(vec);
    printVector(vec);
    return 0;
}