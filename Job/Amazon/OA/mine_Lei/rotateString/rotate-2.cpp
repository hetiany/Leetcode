int isRotation(string word1, string word2) {
	if (word1 == "" || word2 == "" || word1.size() != word2.size())
		return -1;
	string newStr = word1 + word2;
	if (newStr.find(word2) != string :: npos) 
		return 1;
	return -1;
}