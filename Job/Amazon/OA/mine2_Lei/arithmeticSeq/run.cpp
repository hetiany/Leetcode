int find (int* nums, int n) {
	if (n < 3) return 0;
	int left = 0, right = 1;
	int diff = nums[1] - nums[0];
	int cnt = 0;
	while (right < n - 1) {
		if (diff != nums[right + 1] - nums[right]) {
			cnt += (right - left - 1) * (right - left) / 2;
			if (cnt > 100000000) {
				return	-1;
			}
			diff = nums[right + 1] - nums[right];
			left = right;
		}
		right ++;
	}
	cnt += (right - left - 1) * (right - left) / 2;
	return cnt > 100000000 ? -1 : cnt;
}