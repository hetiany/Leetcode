//using template, hash table, two pointer, and count
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
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
            while(counter > k) {
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