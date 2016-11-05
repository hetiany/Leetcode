//Find online, 06/12/2016
class Solution {
public:
    string reverseVowels(string s) {
        string::iterator p1 = s.begin(), p2 = s.end() - 1;
        string vowels = "aeiouAEIOU";
        while(p1 < p2) {
            while((vowels.find(*p1) == string::npos) && (p1 < p2)) {
                p1++;
            }
            while((vowels.find(*p2) == string::npos) && (p1 < p2)) {
                p2--;
            }
            if(p1 < p2) swap(*p1, *p2);
            p1++;
            p2--;
        }
        return s;
    }
};


//my code
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> store = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int begin = 0, end = s.size() - 1;
        while(begin < end) {
            while(begin < end && store.find(s[begin]) == store.end()) {
                ++begin;
            }
            while(begin < end && store.find(s[end]) == store.end()) {
                --end;
            }
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};