/* 
**Reverse the bits of a 64-bit number, eg, reverse of 13 i.e. (1101) is 11 (1011).
**Brute force solution for reversing bits in a number. Swap the digits from front and end, repeatedly.
*/
#include <bits/stdc++.h>
using namespace std;

int sizeofInt= sizeof(int)*8;
int reverse(int);
int swap(int, int, int);

int main() {
	// your code goes here
	long num;
	cin>>num;
	cout<<reverse(num);
	return 0;
}

int reverse(int num){
	int noOfBits= ceil(log2(num));
	int i,j;
	for (i=0, j=noOfBits-1; i<j ; i++,j--){
		num= swap(num,i,j);
	}
	return num;
}

int swap(int num, int i, int j){
	if(((num>>i)&1) != ((num>>j))&1){
		int bitmask= ((1L<<i) | (1L<<j));
		num ^= bitmask;
	}
	return num;
}