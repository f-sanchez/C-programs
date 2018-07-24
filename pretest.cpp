#include<iostream>

using namespace std;

int main() {

	/*
	int x = 65535;

	cout << (int)(unsigned char)x;
	cin >> x;
	*/
	
	/*
	int a = 1, b = 1;

	cout << a++ << endl;
	cout << ++b << endl;
	cout << a << endl << b;
	*/

	/*cout << 21 << endl << 0x21 << endl << 021;*/

	/*
	int a = 7, b = 3, c = 4;
	cout << ((((c | b) ^ 2) &a) << 2) << 2 << endl;
	cout << ((((a | b) ^ 2) &c) << 2) << 2;
	*/

	char byBuf[10];
	memset(byBuf, 0x30, 9);				//ascii of 0x30 = 0; 000000000
	*(byBuf + 5) = 0x31;				//ascii of 0x31 = 1
	*(byBuf + 9) = 0;
	cout << byBuf;

	int n;
	cin >> n;
	return 0;
}