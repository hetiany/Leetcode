#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int cost_per_cut, int metal_price, vector<int>& lengths) {
        int maxLen = 0;
        for (int length : lengths) {
            if (length > maxLen) {
                maxLen = length;
            }
        }

        int maxProfit = 0;
        for (int i = 1; i < maxLen; i++) {
            int sumLen = 0;
            int sumSpend = 0;
            int sumLeft = 0;
            for (int length : lengths) {
                sumLen += length;
                if (length % i == 0) {
                    sumSpend += (length / i - 1);
                } else {
                    sumSpend += (length / i);

                }
                sumLeft += (length % i);

            }

            int profit = sumLen * metal_price - sumSpend * cost_per_cut - sumLeft * metal_price;

            if (profit > maxProfit) {
                maxProfit  = profit;
            }
        }

        return maxProfit;

    }

};


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int first;
    int second;
    cin >> first;
    cin >> second;

    int k;
    cin >> k;

    vector<int> vec;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    Solution s;
    cout << s.maxProfit(first, second, vec) << endl;

    return 0;

}