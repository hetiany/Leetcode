//check两个数是否是grey code（两个bit表达式，只有一位不同，所以用XOR，result里应该只有一个1）

// Example program
#include <iostream>
#include <string>
using namespace std;

int grayCheck(unsigned char term1, unsigned char term2){
	unsigned int x = term2 ^ term1;
	if (x == 0) return -1;
	if ((x&(x - 1)) == 0) return 1;
	return -1;
	}
	
int main()
{
    //unsigned char term1 = 0x10;
    unsigned char term1 = 0x30;
    unsigned char term2 = 0x30;
    cout<< grayCheck (term1, term2);
}
