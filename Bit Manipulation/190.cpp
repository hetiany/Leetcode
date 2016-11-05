//find online
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++) {
           result = (result << 1) + (n >> i & 1); 
        }
        return result;
    }
};


//Find online
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            m <<= 1;
            m |= n & 1;
        }
        return m;
    }
};


//my code, 06/12/2016
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; ++i) {
            result <<= 1;
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};

//my code, 07/17/2016
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 31; ++i) {
            result += n >> i & 1;
            result <<= 1;
        }
        result += n >> 31 & 1;
        return result;
    }
};

