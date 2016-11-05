//Find online
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int> > pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};


//Find online
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) {
            ++m[num];
        }
        vector<vector<int>> buckets(nums.size() + 1); 
        for(auto p : m) {
           buckets[p.second].push_back(p.first); 
        }
        vector<int> ans;
        for(int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                     break;
                }
            }
        }
        return ans;
    }
};


//changed base on above answer, this is better
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) {
            ++m[num];
        }
        vector<vector<int>> buckets(nums.size() + 1); 
        for(auto p : m) {
           buckets[p.second].push_back(p.first); 
        }
        vector<int> ans;
        for(int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                     return ans;
                }
            }
        }
        return ans;
    }
};


//my code, 07/07/2016
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) {
            ++m[num];
        }
        vector<vector<int> > buckets(nums.size() + 1); 
        
        for(auto p : m) {
           buckets[p.second].push_back(p.first); 
        }
        
        vector<int> ans;
        for(int i = buckets.size() - 1; i >= 0; --i) {
            
            if(buckets[i].size() > 0 && ans.size() < k) {
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
                if (ans.size() >= k) {
                    break;
                }
            } 
        }
        return ans;
    }
};


//my code, 07/11/2016, using bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(!nums.size()) {
            return result;
        }
        unordered_map<int, int> store;
        for(auto i: nums) {
            ++store[i];
        }
        vector<vector<int> > bucket(nums.size() + 1);
        for(auto p: store) {
            bucket[p.second].push_back(p.first); 
        }
        for(int i = bucket.size() - 1; i >= 0; --i) {
            if(!bucket[i].empty()) {
                for(int m: bucket[i]) {
                    result.push_back(m);
                    if(result.size() == k) {
                        return result;
                    }
                }
            }    
        }
        return result;
    }
};