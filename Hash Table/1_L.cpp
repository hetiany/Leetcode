#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vec;
        unordered_map<int, int> map;
        for(int i = 0; i < numbers.size(); ++i){
            int numberToFind = target - numbers[i];
            if(map.find(numberToFind) != map.end()){
                vec.push_back(map[numberToFind] + 1);
                vec.push_back(i + 1);
                return vec;
            }
            map[numbers[i]] = i;
        }
        return vec;
    }
};
 
void printVector(vector<int> v){
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}
 
int main(int argc, char const *argv[])
{
    unordered_map<int, int> m;
    // cout << m[0] << endl;
 
    Solution sol;
    //vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    vector<int> res;
    res = sol.twoSum(v, 12);
    printVector(res);
    return 0;
}