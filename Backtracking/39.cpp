#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//Find online
//Combination Sum 
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
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
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }   
    }
};



//my code, 05/25/2016
//Time complexity(n!)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<std::vector<int> > result;
        vector<int> temp;
        get_result(candidates, target, result, temp, 0);
        return result;
    }
private:
    void get_result(vector<int> &candidates, int target, vector<vector<int> > &result, 
                    vector<int> temp, int begin) {
        int total = 0;
        for(int i = 0; i < temp.size(); ++i) {
            total += temp[i]; 
        }
        if( target == total) {
            result.push_back(temp);
            return ;
        }
        if(target < total) {
            return ;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            //notice the sentence don't have i+1
            get_result(candidates, target, result, temp, i);
            temp.pop_back();
        } 
    }
};

//my code, 09/26/2016
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(!candidates.size()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        get_result(candidates, temp, res, target, 0);
        return res;
    }
    void get_result(vector<int>& candidates, vector<int> temp, vector<vector<int> >& res, int target, int begin) {
        if(target == 0) {
            res.push_back(temp);
            return ;
        }
        if(target < 0) {
            return ;
        }
        for(int i = begin; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            get_result(candidates, temp, res, target - candidates[i], i);
            temp.pop_back();
        }
    }
};


int main(){
	return 0;
}