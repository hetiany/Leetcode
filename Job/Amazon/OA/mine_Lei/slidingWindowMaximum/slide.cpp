int * minSlidingWindow (int * nums, int n, int k) {
	deque<int> que;
	if (k == 1) return nums;
	int res = new int[n - k + 1];
	
	for (int i = 0; i < n; ++i) {
		if (!que.empty() && que.front() == i - k) {
			que.pop_front();
		}
		while (!que.empty() && nums[i] < nums[que.back()]) {
			deq.pop_back();
		}
		que.push_back(i);
		if (i >= k - 1)
			res[index++] = nums[que.front()];
	}
	return res;
}