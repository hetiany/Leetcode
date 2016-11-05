//Find online
class Solution {
public:
        string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};

//My code, 07/05/2016
class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.empty() || secret.size() != guess.size()) {
            return "0A0B";
        }
        string result;
        int store_secret[10] = {0};
        int store_guess[10] = {0};
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++bull;
            } else {
                ++store_secret[secret[i] - '0'];
                ++store_guess[guess[i] - '0'];
            }
        }
        for(int i = 0; i <= 9; ++i) {
            cow += min(store_secret[i], store_guess[i]);
        }
        result = to_string(bull) + 'A' + to_string(cow) + 'B';
        return result;
    }
};