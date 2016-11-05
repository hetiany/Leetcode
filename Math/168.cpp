//Find online
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0){
            res = char('A' + (n - 1) % 26) + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};


//Find online
class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n > 0){
            n--;
            result.insert(result.begin(), char('A' + n % 26));
            n /= 26;
        }
        return result;
    }
};