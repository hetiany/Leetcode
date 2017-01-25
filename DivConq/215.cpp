//my code, can be accept, but not cortect
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - k];;
    }
};

//Find online, using priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop(); 
        }
        return pq.top();
    }
};

//Find online, using multiset
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        int n = nums.size();
        for (int i = 0; i < n; i++) { 
            mset.insert(nums[i]);
            if (mset.size() > k) {
                mset.erase(mset.begin()); 
            }
        }
        return *mset.begin();
    }
};


//Find online, using quicksort
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) {
            return 0;
        }
        if(nums.empty()) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};


//my code, using quick sort
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            while (l <= r && nums[l] >= pivot) {
                l++; 
            }
            while (l <= r && nums[r] <= pivot) {
                r--;
            }
            if (l < r) {
                swap(nums[l++], nums[r--]);
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            }
            if (pos > k - 1) {
                right = pos - 1;
            } else{
                left = pos + 1;
            } 
        }
    }
};


//my code, 06/22/2016, using quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) {
            return 0;
        }
        if(nums.size() == 0) {
            return 0;
        }
        return get_result(nums, k, 0, nums.size() - 1);
    }
    
    int get_result(vector<int>& nums, int k, int left, int right) {
        //For here, I can use if(left <= right)
        //if(left <= right) { 
            int pivot = nums[left];
            int l = left + 1, r = right;
            while(l <= r) {
                while(l <= r && nums[l] >= pivot) {
                    ++l;
                }
                while(l <= r && nums[r] <= pivot) {
                    --r;
                }
                if(l <= r) {
                    swap(nums[l], nums[r]);
                    ++l;
                    --r;
                }
            }
            
            swap(nums[left], nums[r]);
            
            if(k == r + 1) {
                return nums[r];
            }
            if(k > r + 1) {
                return get_result(nums, k, r + 1, right);
            }
            if(k < r + 1) {
                return get_result(nums, k, left, r - 1);
            }
            return 0;
        //} 
    }
};



//Find online, using heap sort
class Solution {
public:   
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};



//my code, 06/20/2016
class Solution {
public:
    void heap_adjust(vector<int> &nums, int begin, int end) {
        //int cur = begin;
        int left = 2 * begin + 1;
        int right = 2 * begin + 2;
        int maxIdx = begin;
        if(left <= end && nums[left] > nums[maxIdx]){
            maxIdx = left;
        }
        if(right <= end && nums[right] > nums[maxIdx]){
            maxIdx = right;
        }
        if(maxIdx != begin){
            swap(nums[begin], nums[maxIdx]);
            heap_adjust(nums, maxIdx, end);
        }    
    }

    void buid_heap(vector<int> &nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) { // build max heap
            heap_adjust(nums, i, nums.size() - 1);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        buid_heap(nums);
        int n = nums.size() - 1;
        for(int i = 0; i < k; ++i){
            if(i == k - 1) {
                return nums[0];
            }
            swap(nums[0], nums[n]);
            heap_adjust(nums, 0, --n);
        }
        return 0;
    }
};