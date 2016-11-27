bool isVowel (char ch) {
	return (ch == 'a' || ch == 'A' ||ch == 'e' || ch == 'E' ||ch == 'i' || ch == 'I' ||ch == 'o' || ch == 'O' ||ch == 'u' || ch == 'U');
}
char * removeVowel(char * s) {
	char * res = new char[strlen(s) + 1];
	int index = 0;
	for (int i = 0; i < strlen(s); ++i){
		if (isVowel(s[i])) {
			res[index++] = s[i];
		}
	}
	res[index] = '\0';
	return res;
}

// char * removeVowel(char * s) {
// 	char * res = new char[strlen(s) + 1];
// 	char * dict = "aeiouAEIOU";
// 	char *pos = strpbrk(p, dict);
// 	strcat (res,  
// 	while (pos) {

// 	}
// }