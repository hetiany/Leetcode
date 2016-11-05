//my code, runtime error
class Solution {
public:
    Solution(vector<int> nums) {
        store = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        sort(store.begin(), store.end());
        return store;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int total = 0;
        for(int i = 1; i <= store.size(); ++i) {
            total *= i;
        }
        int count = rand() % total;
        vector<int> result;
        get_result(store, 0, count, result);
        return result;
    }
    void get_result(vector<int>& store, int begin, int& count, vector<int> result) {
        if(!store.size()) {
            return ;
        }
        if(begin == store.size()) {
            --count;
            if(count == 0) {
                result =  store;
                return ;
            }
        }
        for(int i = begin; i < store.size(); ++i){
            swap(store[i], store[begin]);
            get_result(store, begin + 1, count, result);
            swap(store[i], store[begin]);
        }
        
    }

private:
    vector<int> store;
};



//Find online
class Solution {
public:
    Solution(vector<int> nums) {
        store = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return store;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(store);
        //cannot understand this for loop ????
        for (int i = 0; i < result.size(); i++) {
            int pos = rand() % (result.size() - i);
            swap(result[i + pos], result[i]);
        }
        return result;
    }
    
private:
    vector<int> store;
};

