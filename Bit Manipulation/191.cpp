//my code, 07/16/2016
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            if(n & 1) {
                ++res;
            }
            n >>= 1;
        }
        return res;
    }
};

//my code, 07/16/2016
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            if( n >> i & 1) {
                ++res;
            }
        }
        return res;
    }
};