
int twoSumCount(vector<int>& nums, int target)
{
	int n = nums.size();
	if (n == 0) return 0;
	int result = 0;
	unordered_set<int> st;
	for (int i = 0; i < n; ++i)
		{
			if (!st.count(target - nums[i]))
				result ++;
			else st.insert(nums[i]);
		}	
		return result;
}

int twoSumCount(vector<int>& nums, int target)
{
	int n = nums.size();
	if (n == 0) return 0;
	int result = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		if (mp.count(target - nums[i]))
			{
				result++;
				mp[target - nums[i]]--;
				if (mp[target - nums[i]] == 0)
					mp.erase(target - nums[i]);
			}
		else mp[nums[i]]++;
	}
	return result;
}

