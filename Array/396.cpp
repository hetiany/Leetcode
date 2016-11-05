//allsum = 0*A[0] + 1*A[1] + 2*A[2] + 3*A[3] = A[1] + 2A[2] + 3A[3]
//sum = A[0] + A[1] + A[2] + A[3]
//allsum = A[0] + A[1] + A[2] + A[3] - 4*A[3] + allsum
//       = A[0] + 2A[1] + 3A[2]


//Find online
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        long long sum = 0,allsum = 0;
        for(int i = 0;i < len; ++i) {
            sum += A[i];
            allsum += i * A[i];
        }
        long long res = allsum;
        for(int i = len - 1; i >= 1; --i) {
            allsum += sum - len * A[i];
            res = max(res, allsum);
        }
        return res;
    }
};


//my code, time limit exceeded
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(!A.size()) {
            return 0;
        }
        int res = 0;
        int maxrot = INT_MIN;
        vector<int> rotate;
        for(int i = 0; i < A.size(); ++i) {
            rotate.push_back(i);
        }
        int len = A.size();
        while(len) {
            for(int i = 0; i < A.size(); ++i) {
                res += A[i] * rotate[i];
                ++rotate[i];
                if(rotate[i] == A.size()) {
                    rotate[i] = 0;
                }
            }
            maxrot = max(res, maxrot);
            res = 0;
            --len;
        }
        return maxrot;
        
    }
};