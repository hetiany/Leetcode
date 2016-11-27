//判断string1和string2是否互为right rotation。比如：abcd和cdab
//如果s2 是 s1+s1的substring，正确
#include <iostream>
#include <cstring>
using namespace std;

// int isRotation(string word1, string word2) {
// 	if(word1 == "" || word2 == "" || word1.length() != word2.length() 
// 				|| word1.length() == 0 || word2.length() == 0){
// 			return -1;
// 		}
// 		string newStr = word1 + word1;
// 		//find(str.begin(), end(str), char); find char and  header file <algorithm>;
// 		if (newStr.find(word2) != string :: npos)
// 			return 1;
// 		else return -1;
// }
int rightRotation(char * word1, char* word2)
{
	int w1_len = strlen(word1);
	int w2_len = strlen(word2);
	if (w1_len != w2_len) return false;
	char * new_arr = new char[w1_len + w2_len + 1];
	strcpy(new_arr, word1);
	strcat(new_arr, word1);
	if (strstr(new_arr, word2))
		return 1;
	else return -1;
}
int main(int argc, char const *argv[])
{
	// string word1 = "12345";
	// string word2 = "45123";
	cout<<rightRotation("12545", "45123");
	return 0;
}