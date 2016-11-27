public static int isRotation(String word1, String word2) {
	if (word1 == null || word2 == null || word1.length() == 0 || word2.length() == 0 || word1.length()
		!= word2.length())
		return -1;
	String str = word1 + word2;
	return str.contains(word2) ? 1 : -1;
}