#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//compile, g++ -std=c++0x char.cpp,  g++ -std=gnu++0x

int main() {
	int a = 122;
	char c = (char)a;
	cout << (char)a << endl;


	//atoi, leetcode question, implement atoi
	int i;
    char buffer[2] = {'7', '3'};
    i = atoi (buffer);
    printf ("The value entered is %d. Its double is %d.\n",i,i*2);

    //itoa ??
    int j;
    char store[33];
    printf("Enter a number: ");
    //scanf("%d",&j);
    //why cannot use itoa() ? ?
    //itoa(j,store,10);
    printf("decimal: %s\n",store);


    //to_string
    int b = 100;
    cout << to_string(b) << endl;

    //stoi
    string str_dec = "2001, A Space Odyssey";
  	string str_hex = "40c3";
  	string str_bin = "-10010110001";
  	string str_auto = "0x7f";

  	string::size_type sz;   // alias of size_t

  	int i_dec = stoi (str_dec, &sz, 10);
  	int i_hex = stoi (str_hex, nullptr, 16);
  	int i_bin = stoi (str_bin, nullptr, 2);
  	int i_auto = stoi (str_auto,nullptr, 0);

  	cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  	cout << str_hex << ": " << i_hex << '\n';
  	cout << str_bin << ": " << i_bin << '\n';
  	cout << str_auto << ": " << i_auto << '\n';

	return 0;
}