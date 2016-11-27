//O(n^2)
string longestPalindrome(string s) 
{
	if (s == ""|| s.size() == 1) 
		return s;
	int n = s.size();
	int start = 0, i, j = 0;
	int min_start = 0, max_len = 1;
	for (; start < n - max_len / 2;)//should be < 
	{
		i = start, j = start; 
		while (j + 1 < n && s[j] == s[j + 1] )//skip dups
			 j++;
		start = j + 1;  // update new start here "as the "mid""
		while (i > 0 && j < n - 1 && s[i - 1] == s[j + 1])
		{
			--i;
			++j;
		}
		int new_len = j - i + 1;
		if (new_len > max_len)
		{
			min_start = i;
			max_len = new_len;
		}
	}
	return s.substr(min_start, max_len);
}