#include <vector>
#include <algorithm>
//#include <unordered_map>
#include <iostream>
using namespace std;

//Longest Substring Without Repeating Characters????
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){return 0;}
        unordered_map<int, int> mapping;
        int maxlength = 0;
        int premaxlength = 0;
        for(int i=0; i<s.size(); ++i){
        	if( mapping.find(s[i]) == mapping.end() ){
        		mapping[s[i]] = mapping.size()+1;
        		++maxlength;
        	}else{ if( maxlength >= premaxlength){
        				premaxlength = maxlength;
        	   		}
        	   		maxlength = mapping.size()-mapping[s[i]];
        	   		mapping.erase(s[i]);
        	   		mapping[s[i]] = mapping.size()+1;
        	   		cout << "maxa" << maxlength << endl;
        	   		++maxlength;
        	   		cout << "max" << maxlength << endl;
        	}
        }
        cout << maxlength << premaxlength << endl;
        return maxlength = maxlength > premaxlength? maxlength:premaxlength;  
    }
};*/

//Find online
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mymap(256,-1);
        int i,last = 0,ans = 0;
        for(i = 0; i < s.length(); i++) {
            if(mymap[s[i]] == -1 || mymap[s[i]] < last)
                ans = max(ans, i - last + 1);
            else
                last = mymap[s[i]] + 1;
            mymap[s[i]] = i;
        }
        return ans;
    }
};

//my code, 05/24/2016, changed by above answer, using vector instead of hash table
//the firstpos is the first postioon of current substring
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mymap(256,-1);
        int i, firstpos = 0, curlen = 0, max = 0;
        for(i = 0; i < s.length(); i++) {
            if(mymap[s[i]] == -1 || mymap[s[i]] < firstpos) {
                curlen = i - firstpos + 1;
            } else {
                firstpos = mymap[s[i]] + 1;
            }
            mymap[s[i]] = i;
            if(curlen > max) {
                max = curlen;
            }
        }
        return max;
    }
};



//Find online????
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int longest = 0, m = 0;

        for (int i = 0; i < s.length(); i++) {
            m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
            charIndex[s[i]] = i;
            longest = max(longest, i + 1 - m);
        }
        return longest;
    }
};


//Find online, using hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        int d = 1, maxLen = 1;
        unordered_map<char,int> map;
        map[s[0]] = 0;
        for(int i = 1; i < s.size(); i++) {
            if(map.find(s[i]) == map.end() || map[s[i]] < i-d) {
                d++;
            }
            else {
                 d = i- map[s[i]];
            }
            map[s[i]] = i;
            if(d > maxLen) {
                maxLen = d;
            }
        }
        return maxLen;
    }
};



//my code, 05/24/2016, changed by solution using hash table
//test case
//abba  
//abca
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int d = 0, maxLen = 0;
        unordered_map<char,int> map;
        for(int i = 0; i < s.size(); i++) {
            if(map.find(s[i]) == map.end() ) {
                d++;
            }
            else if(map[s[i]] < i-d) { 
                d++;
            } else {
                d = i- map[s[i]];
            }
            map[s[i]] = i;
            if(d > maxLen) {
                maxLen = d;
            }
        }
        return maxLen;
    }
};

//my code, 10/17/2016
//test case: abba, abca, abcadefb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return s.size();
        }
        unordered_map<int, int> record;
        int maxLen = INT_MIN, curLen = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(record.find(s[i]) == record.end()) {
                record[s[i]] = i;
                ++curLen;
            } else {
                if(i - record[s[i]] <= curLen) {
                    curLen = i - record[s[i]];
                    record[s[i]] = i;
                } else {
                    ++curLen;
                    record[s[i]] = i;
                }
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};


//Find online, using template
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter = 0, begin = 0, end = 0, d = INT_MIN;
        while(end < s.size()){
            if(map[s[end]] > 0) {
                counter++;
            }
            map[s[end]]++;
            end++;
            while(counter > 0) {
               if(map[s[begin]] > 1) {
                   counter--; 
               }
               map[s[begin]]--;
               begin++;
            }
            d = max(d, end - begin); //while valid, update d
        }
        if(d == INT_MIN) {
            return 0;
        }
        return d;

    }
};


int main(){
    //a = "abba"  
	string a = "abcddcbaf";
	Solution sol;
	cout << sol.lengthOfLongestSubstring(a) << endl;
	return 0;
}