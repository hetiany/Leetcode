#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		vector<int> charIndex(256, -1);
	int longest = 0, m = 0;
  for(int i = 0; i < s.length(); ++i ){
			m = max(charIndex[s[i]] + 1, m);
			charIndex[s[i]] = i;
			longest = max(longest, i + 1 - m);
	}
	return longest;
	}


};



int main(){
	
  
   return 0;

}
