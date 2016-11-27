#include <iostream>
#include <unordered_set>
#include <algorithm>
//#include "boost\algorithm\string.hpp"
using namespace std;

//http://blog.csdn.net/justin12zhu/article/details/5649236
 int toLower( int c )
{
       return toupper( c ) ;
}
 // 标准库重载了一个touppe函数，而GCC完全由C库去提供重载，
//而glibc做不到这一点，所以在编译的时候g++就认为这个函数有歧义了

string removeVowel1(string s, string& v)
{
	string res;
	transform(v.begin(), v.end(),v.begin(),  toLower);//包装函数	
	//将toupper转换为一个返回值为int，参数只有一个int的函数指针：
	//std::transform(s.begin(), s.end(), s.begin(), (int(*)(int)) toupper);
	unordered_set<char>st (v.begin(), v.end());
	transform(s.begin(), s.end(), s.begin(), ::tolower);//全局命名空间
	for (int i = 0; i < s.size(); ++i)
		{
		    if (st.count(s[i]) == 0)
			res.push_back(s[i]);
		}
	return res;
}



string removeVowel(string& s, string& v){
	size_t found = s.find_first_of(v);
	while (found != string :: npos)
	{
		s.erase(s.begin() + found);
		found = s.find_first_of(v, found);
	}
	return s;
}

int main(int argc, char const *argv[])
{
	string s = "abcdeio";
	string vowel = "aeiouAEIOU";
	cout<< removeVowel (s, vowel);
	return 0;
}