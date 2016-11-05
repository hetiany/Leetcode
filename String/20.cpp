#include <iostream>
#include <string>
#include <stack>
using namespace std;


//Find online, using stack
class Solution {
public:
    bool isValid(string s) {
            // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0){
        	return true;
        }
        stack<char> st;
        for (int i=0;i<s.size();i++){                   
            if ((s[i]=='(') ||(s[i]=='[') ||(s[i]=='{')) {st.push(s[i]);}
            else{  
                if (st.empty()){return false;}
                if ((s[i]==')') && (st.top()!='(')) {return false;}
                if ((s[i]=='}') && (st.top()!='{')) {return false;}
                if ((s[i]==']') && (st.top()!='[')) {return false;}
                st.pop();
            }
             
        }
        return st.empty();
    }
};

//my code, 10/03/2016
class Solution {
public:
    bool isValid(string s) {
        if(!s.size()) {
            return true;
        }
        stack<int> store;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                store.push(s[i]);
            } else {
                if(!store.size()) {
                    return false;
                } else if(s[i] == ')' && store.top() == '(') {
                    store.pop();
                } else if(s[i] == ']' && store.top() == '[') {
                    store.pop();
                } else if(s[i] == '}' && store.top() == '{') {
                    store.pop();
                } else {
                    return false;
                }
            }
        }
        if(store.size()) {
            return false;
        }
        return true;
    }
};


//my code, 10/17/2016
class Solution {
public:
    bool isValid(string s) {
        if(!s.size()) {
            return false;
        }
        stack<char> store;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                store.push(s[i]);
            } else {
                if(store.size() == 0) {
                    return false;
                } else {
                    char temp = store.top();
                    if(temp == '(' && s[i] == ')' ||
                       temp == '[' && s[i] == ']' ||
                       temp == '{' && s[i] == '}') {
                           store.pop();
                       } else {
                           return false;
                       }
                }
            }
        }
        if(store.size() == 0) {
            return true;
        }
        return false;
    }
};


int main(){
	Solution a;
    string b = "{(())";
    cout << a.isValid(b) << endl;
	return 0;
}