// The queue size need not be the same as the window’s size.
// Remove redundant elements and the queue should store only elements that need to be considered.
vector<int> minSlidingWindow(vector<int> & nums, int k)
{
	if (k == 1) return nums;
	deque<int> dq;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i)
	{	
	    if (!dq.empty() && dq.front() == i - k) dq.pop_front();
	 	while (!dq.empty() && nums[dq.back()] > nums[i])
	 			dq.pop_back();
	 	dq.push_back(i);
	 	if (i >= k - 1)
				res.push_back(nums[dq.front()]);
	}
	return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;
    multiset<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        if (i >= k)
            w.erase(w.find(nums[i-k]));
        w.insert(nums[i]);
        if (i >= k-1)
            result.push_back(*w.rbegin());
    }
    return result;
}
