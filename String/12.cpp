//Find online, Java
public class Solution {
    public String intToRoman(int num) {
        int[] weights = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] tokens = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder rs = new StringBuilder("");
        int start = 0;
        while(num > 0){
            for(int i = start; i < 13; i++) {
                if(num >= weights[i]) {
                    num -= weights[i];
                    rs.append(tokens[i]);
                    break;
                }
                start = i + 1; // skip those impossible check, make it faster
            }
        }
        return rs.toString();
    }
};


//my code, changed by above
class Solution {
public:
    string intToRoman(int num) {
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;
        int start = 0;
        int i;
        while(num > 0) {
            for(i = start; i < 13; ++i) {
                if(num >= number[i]) {
                    result += roman[i];
                    num -= number[i];
                    break;
                }
                /*the sentence below can be deleted*/
                start = i + 1;
            }
            
        }
        return result;
    }
};

//my code, 09/28/2016
class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        vector<int> integer{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string res;
        int start = 12;
        while(num) {
            for(int i = start; i >= 0; --i) {
                if(num >= integer[i]) {
                    res += roman[i];
                    num = num - integer[i];
                    break;
                }
                start = i;
            }
        }
        return res;
    }
};
