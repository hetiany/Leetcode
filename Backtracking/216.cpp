#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


//my code
//Combination Sum III
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<vector<int> > result_set;
    	vector<int> temp;
    	if(k == 0 || n == 0){
    	    return result_set;
    	}
    	if(k > n){
    		return result_set;
    	}
        int begin = 0;
        int num = 0;
        get_result(k, n, num, begin, temp, result_set);
        return result_set;
    }

    void get_result(int k, int n, int num, int begin, vector<int> temp, 
    						   vector<vector<int> >& result_set){
    	if( n == 0 && num == k){
    		result_set.push_back(temp);
    		return;
    	}

    	for(int i = begin; i < 9; ++i){
    		temp.push_back(i + 1);
    		get_result(k, n-(i+1), num+1, i+1, temp, result_set);
    		temp.pop_back();
    	}
    }
};


//my code, 05/25/2016
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> temp;
        get_result(result, temp, n, k, 1);
        return result;
    }
    void get_result(vector<vector<int> >& result, vector<int> temp, int n, int k, int begin) {
        if(temp.size() == k) {
            int total = 0;
            for(int i = 0; i < k; ++i) {
                total += temp[i]; 
            }
            if(total == n) {
                result.push_back(temp);
                return ;
            }
            //the below if condition can be added or deleted
            if(total > n) {
                return ;
            }     
        }
        for(int i = begin; i <= 9; ++i) {
            temp.push_back(i);
            get_result(result, temp, n , k, i + 1);
            temp.pop_back();
        }
    }
};


//my code, 09/16/2016
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> temp;
        if(!n) {
            return res;
        }
        get_result(res, temp, k, n, 1);
        return res;
    }
    void get_result(vector<vector<int> >& res, vector<int> temp, int k, int n, int begin) {
        if(n == 0 && temp.size() == k) {
            res.push_back(temp);
        }
        if(n < 0) {
            return ;
        }
        for(int i = begin; i <= 9; ++i) {
            temp.push_back(i);
            get_result(res, temp, k, n - i, i + 1);
            temp.pop_back();
        }
    }
};

int main(){
	return 0;
}