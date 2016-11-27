vector<int> WindowSum(vector<int> nums, int k)
{	
	std::vector<int> res;
	int n = nums.size();
	if (k <= 0 || n == 0) return res;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i < k)
		{
			sum += nums[i];
			if (i == k - 1) res.push_back(sum);
		}
		else {
			sum += nums[i] - nums[i - k];
			res.push_back(sum);
		}
	}
	return res;
}

int * WindowSum (int * nums, int k, int len) {
	int sum = 0;
	int * res = new int[len - k + 1];
	int index = 0;
	for (int i = 0;i < len; ++i) {
		sum += nums[i];
		if (i >= k) {
			sum -= nums[i - k];
		}
		if (i >= k - 1)
			res[index++] = sum;
	}
	return res;
}