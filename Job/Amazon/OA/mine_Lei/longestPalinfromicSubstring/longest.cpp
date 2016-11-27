 String longestPalindrome(String s) {
 	int len = s.size();
 	if (len <= 1) return s;
 	int left = 0, right = 0;
 	int maxLen = 1, start = 0; 
 	for (int i = 0; i < len - maxLen / 2;) { // < not <=;
 		left = i, right = i;
 		while ((right + 1) < len && s[right + 1] == s[right]) {
 		++right;
 		}
 		i = right + 1;
 		while (left >= 0 && right < len && s[left] == s[right]) {
 			--left;
 			++right;
 		}
 		if (right - left > maxLen) {
 			maxLen = right - left;
 			start = left;
 		}
 	}
 	return s.substr(start, maxLen);
 }