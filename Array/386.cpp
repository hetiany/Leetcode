//Find online
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rs;
        
        int i = 1, j;
        int k;
        for(;;)
        {
            // append as many zeroes as possible to the previous number
            for(k = 0; i*pow(10,k) <= n; ++k) rs.push_back(i*pow(10,k));
            
            // count continuously until we reach a number that ends with consecutive '9's
            for(j = rs.back()+1; j <= n && (j % 10) != 0; ++j) rs.push_back(j);
            
            // backtrace
            if(j % 10 == 0)
            {
                j--;
            }
            else
            {
                j /= 10;
            }

            // find the last non-'9' digit
            while(j % 10 == 9) j /= 10;
            
            // start a new sub-sequence
            i = j+1;
            
            if(rs.size() >= n) break;
        }

        return rs;
    }
};


//Find online
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int count = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = count;
            if (count * 10 <= n)
                count *= 10;
            else if (count % 10 == 9) {
                count++;
                while (count % 10 == 0)
                    count /= 10;
            }
            else if (count + 1 > n) {
                count /= 10;
                count++;
                while (count % 10 == 0)
                    count /= 10;
            }
            else
                count++;
        }
        return ans;
    }
};