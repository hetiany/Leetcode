//Find online
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b != 0) {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        return sum;
    }
};


//Find online, cannot understand
class Solution {
public:
    int getSum(int a, int b) {
        int base = a ^ b;
        int c[32];
        c[0] = 0;

        for(int i = 1; i < 32; i++) {
            c[i] = (c[i - 1] && (a & 1 || b & 1)) || (a & 1 && b & 1);
            a >>= 1;
            b >>= 1;
        }

        int carry = 0;
        for(int i = 31; i >= 0; i--) {
            carry = (carry << 1) + c[i];
        }
        return base ^ carry;
    }
};