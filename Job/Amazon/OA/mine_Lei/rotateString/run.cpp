int rightRotation(char * word1, char* word2)
{
	int w1_len = strlen(word1);
	int w2_len = strlen(word2);
	if (w1_len != w2_len) return false;
	char * new_arr = new char[w1_len + w2_len + 1];
	strcpy(new_arr, word1);
	strcat(new_arr, word1);
	if (strstr(new_arr, str1))
		return 1;
	else return -1;
}