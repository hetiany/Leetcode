//Find online, using template
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(!s.size()) {
            return 0;
        }
        vector<int> map(128, 0);
        int counter = 0, begin = 0, end = 0, d = INT_MIN;
        while(end < s.size()) {
            if(map[s[end]] == 0) {
                counter++;
            }
            map[s[end]]++;
            end++;
            while(counter > 2) {
                if(map[s[begin]] == 1) {
                    counter--;
                }
                map[s[begin]]--;
                begin++;
            } 
            d = max(d, end - begin);
        }
        return d;

    }
};