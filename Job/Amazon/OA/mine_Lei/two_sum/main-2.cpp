int twoSumCount(int* nums, int target)
{
	int n = nums.size();
	if (n == 0) return 0;
	int result = 0;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		if (mp.count(target - nums[i])) {
			result ++;
			mp[target - nums[i]]--;
			if (mp[target - nums[i]] == 0) {
				mp.erase(target - nums[i]);
			}
		}
		else mp[num[i]]++;
	}
	return result;
}