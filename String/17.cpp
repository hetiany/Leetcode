#include <vector>
#include <string>
//#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


//Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0){
            return res;
        }
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        //cout << res.size() << endl;
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tempres;
            string chars = charmap[digits[i] - '0'];
            for (int k = 0; k < chars.size(); k++) {
                for (int j = 0; j < res.size(); j++) {
                    cout << res[j] + chars[k] << endl;
                    tempres.push_back(res[j] + chars[k]);
                }
            }
            cout << "hello" << endl;
            res = tempres;
        }
        return res;
    }
};


//Find online
class Solution {
public:
        vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        //vector<vector<char> > table;
        vector<vector<char> > table(2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // index 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); // 5
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); // 7
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); // 9

        backtracking(table,res,local,0,digits);
        return res;
    }

    void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, 
                      int index, const string& digits) {
        if(index == digits.size()){
            res.push_back(local);
            return;
        }
    
        for(int i = 0; i < table[digits[index]-'0'].size();i++) {
            local.push_back(table[digits[index]-'0'][i]);
            backtracking(table, res, local, index+1, digits);
            local.pop_back();
        }
    }
};



//my code, 05/28/2016
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
      
        vector<string> store(2, "");
        store.push_back("abc");
        store.push_back("def");
        store.push_back("ghi");
        store.push_back("jkl");
        store.push_back("mno");
        store.push_back("pqrs");
        store.push_back("tuv");
        store.push_back("wxyz");
        string temp;
        get_result(result, digits, store, temp, 0);
        return result;
    }
    void get_result(vector<string>& result, string digits, vector<string> store, string temp, int index) {
        if(digits.empty()) {
            return ;
        }
        if( temp.size() == digits.size() ) {
            result.push_back(temp);
            return ;
        }  
        for(int i = 0; i < store[digits[index] - '0'].size(); ++i) {
            temp.push_back(store[digits[index] - '0'][i]);
            get_result(result, digits, store, temp, index + 1);
            temp.pop_back();
        }
    }
};

//my code, 09/27/2016
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.size()) {
            return res;
        }
        vector<string> record(10);
        record[0] = "";
        record[1] = "";
        record[2] = "abc";
        record[3] = "def";
        record[4] = "ghi";
        record[5] = "jkl";
        record[6] = "mno";
        record[7] = "pqrs";
        record[8] = "tuv";
        record[9] = "wxyz";
        string temp;
        get_result(digits, res, temp, record, 0);
        return res;
    }
    void get_result(string digits, vector<string>& res, string temp, vector<string> record, int index) {
        if(index == digits.size()) {
            res.push_back(temp);
            return ;
        }
        for(int i = 0; i < record[digits[index] - '0'].size(); ++i) {
            temp.push_back(record[digits[index] - '0'][i]);
            get_result(digits, res, temp, record, index + 1);
            temp.pop_back();
        }
    }
};


int main(){
    Solution sol;
    sol.letterCombinations("23");
	return 0;
}