//Find online
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};


//Lei
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res(n1 + n2, '0');
        int i, j; 
        for(i = n1 - 1; i >= 0; --i) {  //2
            int carry = 0, m1 = num1[i] - '0';
            for (j = n2 - 1; j >= 0; --j) {  //1 
                int m2 = num2[j] - '0';
                int product = m1 * m2;
                int sum = (res[i + j + 1] - '0') + product + carry;
                res[i + j + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            if (carry > 0) {
                res[i + j + 1] = (res[i + j + 1] - '0' + carry) + '0';
            }
        }
        i = 0;
        while (res[i] == '0') {
            i++;
        }
        return i == n1 + n2 ? "0" : res.substr(i);
    }
};
