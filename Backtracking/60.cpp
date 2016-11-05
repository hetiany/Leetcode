#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//my code, time limit exceed
class Solution {
public:
    string getPermutation(int n, int k) {

        //vector<int> temp;
        string result;
        vector<int> nums;
        int sum = 1;
        vector<vector<int> > permuta_sets;
        
        for(int i = 1; i <= n; ++i){
        	sum  *= i;
        }

        if(n == 0 || k == 0){
        	return result;
        }

        if(k > sum){
        	return result;
        }

        for(int i = 0; i < n; ++i){
        	nums.push_back(i + 1);
        }

        int begin = 0;
        get_result(k, begin, result, nums, permuta_sets);
        return result;
    }

    void get_result( int k, int begin, 
    				string& result, vector<int>& nums,
    				vector<vector<int> > permuta_sets ){

    	if( begin == nums.size() ){
    		permuta_sets.push_back(nums);
    		if(permuta_sets.size() == k){
    			for(int i = 0; i < nums.size(); ++i){
    			    result.push_back(nums[i]);
    		    }
    		}
    		return;
    	}

    	for(int i = begin; i < nums.size(); ++i){
    		swap(nums[i], nums[begin]);
    		get_result(k, begin + 1, result, nums, permuta_sets);
    		swap(nums[i], nums[begin]);
    	}
    }
};


//Find online, it's right, why???
class Solution {
public:
 void swap(string &str,int st, int l){
        for (int i=st+l;i>st;--i){
            char tmp = str[i];
            str[i]=str[i-1];
            str[i-1]=tmp;
        }
    }
 
    void getP(string &str,int &st, int &n,int &k, int *nf){
        if (k==0 || st>n-1){
            return;
        }else{
            swap(str,st,k/nf[n-st-1]);
            k=k%nf[n-st-1];
            getP(str,++st,n,k,nf);
        }
    }
 
    string getPermutation(int n, int k) {
        string str="";
        int nf[10]={1,1,2,6,24,120,720,5040,40320,362880}; //n factorail
        for (int i=1;i<=n;i++){str+=char(i+'0');}
        int st=0;
        getP(str,st,n,--k,nf);
        return str;
    }
};


//my code, 05/26/2016, time limit exceed
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string temp;
        for(int i = 0; i < n; ++i) {
            temp += to_string(i + 1);
        }
        get_result(result, temp, n, k, 0);
        return result;
    }
    void get_result(string& result, string temp, int n, int& k, int begin) {
        if(begin == n) {
            --k;
        }
        if(k == 0) {
            //k = -1;
            --k;
            result = temp;
            return ;
        }
        for(int i = begin; i < n; ++i) {
            swap(temp[i], temp[begin]);
            get_result(result, temp, n, k, begin + 1);
        }
    }
};


//my code, 09/26/2016, time limit exceed
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string temp;
        for(int i = 0; i < n; ++i) {
            temp += to_string(i + 1);
        }
        get_result(result, temp, n, k, 0);
        return result;
    }
    void get_result(string& result, string temp, int n, int& k, int begin) {
        if(begin == n) {
            --k;
            if(k == 0) {
                //--k;
                result = temp;
                return ;
            }
        }
        /*if(k == 0) {
            --k;
            result = temp;
            return ;
        }*/
        for(int i = begin; i < n; ++i) {
            swap(temp[i], temp[begin]);
            get_result(result, temp, n, k, begin + 1);
        }
    }
};

//Find online, 05/28/2016
class Solution {
public:
    string getPermutation(int n, int k) {
        int pTable[10] = {1};
        for(int i = 1; i <= 9; i++){
            pTable[i] = i * pTable[i - 1];
        }
        string result;
        vector<char> numSet;
        numSet.push_back('1');
        numSet.push_back('2');
        numSet.push_back('3');
        numSet.push_back('4');
        numSet.push_back('5');
        numSet.push_back('6');
        numSet.push_back('7');
        numSet.push_back('8');
        numSet.push_back('9');
        while(n > 0){
            int temp = (k - 1) / pTable[n - 1];
            result += numSet[temp];
            numSet.erase(numSet.begin() + temp);
            k = k - temp * pTable[n - 1];
            n--;
        }
        return result;
    }
};


//my code, 09/27/2016
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> total(10, 1);
        for(int i = 1; i <= 9; ++i) {
            total[i] = i * total[i - 1];
        }
        //vector<string> record;
        string record;
        for(int i = 0; i < 9; ++i) {
            //record[i] = to_string(i + 1);
            record += to_string(i + 1);
        }
        while(n > 0) {
            int temp = (k - 1) / total[n - 1];
            res += record[temp];
            record.erase(record.begin() + temp);
            k = k - temp * total[n - 1];
            --n;
        }
        return res;
    }
};


//Lei
class Solution {
public:
    string getPermutation(int n, int k) {d
        string res;
        string ret = "";
        if(n == 1) return "1";
        for(int i = 1; i <= n; i++) {
            res = res + to_string(i);
        }
        for(int i = 1; i <= n; ++i){
            int index = (k - 1) / (factorial(n - i));   
            ret = ret + res[index];
            res.erase(res.begin() + index);
            k = k - factorial(n - i) * index;
        }
        return ret;
    }
    int factorial(int n) {
        if(n == 0) return 1;
        int sum = 1;
        for(int i = 1; i <= n; ++i) {
            sum = sum * i;
        }
        return sum;
    }
};


int main(){
	return 0;
}