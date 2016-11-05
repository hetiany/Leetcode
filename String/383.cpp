//my code
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> record;
        for(int i = 0; i < magazine.size(); ++i) {
            ++record[magazine[i]];
        }
        for(int i = 0; i < ransomNote.size(); ++i) {
            if(record.find(ransomNote[i]) == record.end()) {
                return false;
            } else {
                if(record[ransomNote[i]] > 0) {
                    --record[ransomNote[i]];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

//find online
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazLetters(26, 0);
        for(char m : magazine) {
            magazLetters[m - 'a']++;
        }
        for(char r : ransomNote)
            if(--magazLetters[r -'a'] < 0) {
               return false; 
            }
        return true;
    }
};