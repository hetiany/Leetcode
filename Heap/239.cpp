/*
[1]
[3]
[3,-1]             3
[3, -1, -3]        3
[, , 5]            5
[, 5, 3]           5
[,, 6]             6
[,, 7]             7

[7,3] 6
[7, ,6]

[1 1 1 1 8]       8,
   [1 1 1 8 x]    x < 8 [8,x];   x > 8, [x] 4;
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


i    dq        value  
   (index)
0    0           1     
1    1           3
2   1, 2       3, -1       3
3   1, 2, 3   3, -1, -3    3
    2, 3         -1, -3 
4    4            5        5
5    4, 5        5, 3      5
6    6            6        6
7    7            7        7
*/

//Lei
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //vector<int> result;
        if (k == 1) return nums;
        int n = nums.size();
        int* res = new int[n - k + 1];
        deque<int> dq;
        int index = 0;
        for (int i = 0; i < n ; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) {
                res[index++] = nums[dq.front()];
            }
            if (!dq.empty() && dq.front() == i - k + 1) {
                dq.pop_front();
            }
        }
        return vector<int>(res, res + index);
    }
};

//my code, 11/14/2016
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> store;
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            while(store.size() && nums[i] > nums[store.back()]) {
                store.pop_back();
            }
            store.push_back(i);
            if(i + 1 >= k) {
                cout << nums[store.front()];
                res.push_back(nums[store.front()]);
            }
            if(store.size() && i - k + 1 == store.front()) {
                store.pop_front();
            }
        } 
        return res;
    }
};


//my code, 11/17/2016
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> store;
        vector<int> res;
        if(!nums.size()) {
            return res;   
        }
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(!store.empty() && nums[i] > nums[store.back()]) {
                store.pop_back();
            }
            store.push_back(i);
            if(i >= k - 1) {
                res.push_back(nums[store.front()]);
            }
            if(!store.empty() && store.front() == i - k + 1) {
                store.pop_front();
            }
        }
        return res;
    }
};


//my code, 10/24/2016, time limit exceed
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> store;
        vector<int> res;
        int temp = k;
        if(!nums.size()) {
            return res;
        }
        for(int i = 0; i <= nums.size() - k; ++i) {
            priority_queue<int> store;
            while(temp) {
                store.push(nums[i + temp - 1]);
                --temp;
            }
            temp = k;
            res.push_back(store.top());
            while(temp) {
                store.pop();
                --temp;
            }
            temp = k;
        }
        return res;
    }
};


//Find online, using priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() == 0) return res;
        int l = 0, r = 0;
        auto cmp = [](pair<int, int> a, pair<int, int> b) { return (a.first) < (b.first);};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(r = 0; r < k; r++) {
            pq.push(make_pair(nums[r], r));
        }
        res.push_back(pq.top().first);
        for(r = k; r < nums.size(); r++, l++) {
            pq.push(make_pair(nums[r], r));
            while(pq.size() > k && pq.top().second <= l) pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};


//Find online, using multiset, O(nlgK)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        multiset<int> s;
        for(int i = 0;i < nums.size(); i++){
            if(i < k){
                s.insert(-nums[i]);
            }
            if(i >= k-1){
                if(i != k-1){
                    s.insert(-nums[i]);
                    s.erase(s.find(-nums[i-k]));
                }
                ret.push_back(-(*s.begin()));
            }
        }
        return ret;
    }
};