#include <iostream>
#include <vector>
using namespace std;

//leetcode pdf
class Solution{
public:
	vector<int> plusOne(vector<int>& digits){
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>& digits, int digit){
		int c = digit; //carry bit
		vector<int>::reverse_iterator itr;
		for(itr=digits.rbegin(); itr!=digits.rend(); ++itr){
			*itr += c;
			c = *itr/10;
			*itr %= 10;
		}
		if(c > 0){
			digits.insert(digits.begin(), 1);
		}
	}
};


void printVector(vector<int> &v){
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}


//my code, 07/20/2017
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            if(digits[i] + c > 9) {
                c = (digits[i] + c) / 10;
                digits[i] = (digits[i] + c) % 10;
            } else {
                digits[i] = digits[i] + c;
                c = 0;
            }
        }
        if(c > 0) {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};



int main(){
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(9);
    vec.push_back(8);
    printVector(vec);
    Solution sol;
    vec = sol.plusOne(vec);
    printVector(vec);

	return 0;
}