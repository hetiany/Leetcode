char* longestPalindrome(char* s) {
	int len = strlen(s);
	if (len <= 1) return s;
	int i = 0, j = 0;
	int maxLen = 1, start = 0, minstart = 0;
	for (; start < len - maxLen / 2;) {
		i = start, j = start;
		while (j + 1 < len && s[j] == s[j + 1]) {
			++j;
		}
		start = j + 1;
		while (i - 1 >= 0 && j + 1 < len && s[i - 1] == s[j + 1]) {
			++j;
			--i;
		}
		int new_len = j - i + 1;
		if (new_len > maxLen) {
			maxLen = new_len;
			minstart = i;
		}
	}
	char * res = (char*)malloc((maxLen + 1) * sizeof (char));
    memcpy(res, s + minstart, sizeof(char)*maxLen);
	res[maxLen] = '\0';
	return res;
}