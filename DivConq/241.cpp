//Find online
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
            
        }
        // if the input string contains only number
        if (result.empty()) {
           // result.push_back(atoi(input.c_str()));
           result.push_back(stoi(input));
        }
        return result;
    }
};


//my code, 06/20/2016
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> result_left = diffWaysToCompute(input.substr(0,i));
                vector<int> result_right = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));

                for(int j = 0; j < result_left.size(); ++j) {
                    for(int k = 0; k < result_right.size(); ++k) {
                        if(input[i] == '+') {
                            result.push_back(result_left[j] + result_right[k]);
                        } else if (input[i] == '-') {
                            result.push_back(result_left[j] - result_right[k]);
                        } else if (input[i] == '*') {
                            result.push_back(result_left[j] * result_right[k]);
                        }
                    }
                }


            }
        }
        if(result.empty()) {
            result.push_back(stoi(input));
        }
        return result;
    }
};