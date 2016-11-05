#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

// My code
//Combination Sum II
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<std::vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            if(i != begin && candidates[i] == candidates[i-1]){
                continue;
            }
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
        }         
    }
};


//my code, 05/25/2016
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> temp;
        get_result(result, temp, candidates, target, 0);
        return result;
    }
    void get_result(vector<vector<int> >& result, vector<int> temp, vector<int>& candidates, int target, int begin) {
        int total = 0;
        for(int i = 0; i < temp.size(); ++i) {
            total += temp[i]; 
        }
        if( target == total) {
            result.push_back(temp);
            return ;
        }
        //why the below if condition must be added???????
        if(target < total) {
            return ;
        }
        for(int i = begin; i < candidates.size(); ++i) {
             if(i != begin && candidates[i] == candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            get_result(result, temp, candidates, target, i + 1);
            temp.pop_back();
        }
    }
};

int main(){
	return 0;
}