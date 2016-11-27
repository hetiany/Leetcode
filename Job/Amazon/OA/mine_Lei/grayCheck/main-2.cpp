typedef unsigned char byte;
bool grayCheck(byte term1, byte term2)
{
	byte x = term1 ^ term2;
	int count = 0;
	while (x != 0) {
		x = byte(x & (x - 1));
		count++
	}
	return count == 1;
}

typedef unsigned char byte;
bool grayCheck(byte terms1, byte term2) {
	byte x = term1 ^ term2;
	int count = 0;
	while (x != 0) {
		x = byte(x & (x - 1));
		count++;
	}
	return count == 1;
} 