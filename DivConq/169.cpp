// my code, 06/15/2016, can be accept, but not fast, using unordered_map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> store;
        for(int i = 0; i < nums.size(); ++i) {
            if(store.find(nums[i]) == store.end()) {
                store[nums[i]] = 1;
            } else {
                ++store[nums[i]];
            }
        }
        int first = 0, second = 0;
        for(auto ptr = store.begin(); ptr != store.end(); ++ptr) {
            if(ptr -> second > second) {
                first = ptr -> first;
                second = ptr -> second;
            }
        }
        return first;
    }
};

 
//Find online, using hash_table
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (++counts[nums[i]] > n / 2) {
                return nums[i];
            }
        }
        return 0;
    }
};

//my code, changed on based on Find online hash_table
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (counts.find(nums[i]) == counts.end()) {
                counts[nums[i]] = 1;
                if(counts[nums[i]] > n / 2) {
                    return nums[i];
                }
            } else {
                ++counts[nums[i]];
                if(counts[nums[i]] > n / 2) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};


//my code, sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int index = n / 2;
        return nums[index];
    }
};


//Find online, divide and conquer
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + ( (right - left) / 2 );
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) {
            return lm;
        }
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};


//Find online, Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=nums[0], count = 1;
        for(int i=1; i< nums.size(); i++){
            if(count == 0){
                count++;
                major=nums[i];
            }else if(major == nums[i]){
                count++;
            }else count--;
        }
        return major;
    }
};

//my code
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(count == 0) {
                ++count;
                result = nums[i];
            } else if(result == nums[i]) {
                ++count;
            } else {
                --count;
            }
        }
        return result;
    }
};


//my code, 06/16/2016
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(result == nums[i]) {
                ++count;
            } else if(count == 0) {
                ++count;
                result = nums[i];
            } else {
                --count;
            }
        }
        return result;
    }
};


//my code, 06/22/2016, using quick sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return get_result(nums, 0 , nums.size() - 1);
    }
    int get_result(vector<int>& nums, int left, int right) {
        if(nums.empty()) {
            return 0;
        }
        if(left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int l = get_result(nums, left, mid);
        int r = get_result(nums, mid + 1, right);
        return count(nums.begin() + left, nums.begin() + right + 1, l) > count(nums.begin() + left, nums.begin() + right + 1, r) ? l : r;
    }
};