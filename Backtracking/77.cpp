#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


//Find online
//Combinations
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp(0,k);
        combine(res,temp,0,0,n,k);
        return res;
    }

    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
        }
    }
};

//My code
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > comb_set;
        vector<int> temp;
        int begin = 1;
        int num = 0;
        if(n < k){
            return comb_set;
        }
        if(k == 0){
            return comb_set;
        }
        get_result(n, k, begin, num, comb_set, temp);
        return comb_set;
    }    
        void get_result( int n, int k, int begin, int num, vector<vector<int>>& comb_set, vector<int>& temp ){
            if(num == k){
                comb_set.push_back(temp);
                return;
            }
            for(int i = begin; i <= n; ++i){
                temp.push_back(i);
                get_result(n, k, i + 1, num + 1, comb_set, temp);
                temp.pop_back();
            }
        }
};


//my code, 05/25/2016
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        get_result(result, temp, n, k, 1);
        return result;
    }
    void get_result(vector<vector<int> >& result, vector<int> temp, int n, int k, int begin) {
        if(temp.size() == k) {
            result.push_back(temp);
            return ;
        }
        for(int i = begin; i <= n; ++i) {
            temp.push_back(i);
            get_result(result, temp, n , k, i + 1);
            temp.pop_back();
        }
    }
};


int main(){
	return 0;
}