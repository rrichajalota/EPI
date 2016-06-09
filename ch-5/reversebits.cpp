/* Reverse the bits of a 64-bit number, eg, reverse of 13 i.e. (1101) is 11 (1011).
** Better approach- To use a look-up table. 
** Store the reverse of numbers till 2^16-1 in the table and use them for reversing a 64-bit number. 
** Let the input consist of 4 16-bit words y3,y2,y1,y0. Then the LSBs in the output (reverse form) will come from y3 in reverse order,i.e. 
** if y3 = 1110000000000001 then, 16 LSBs of the result would be 1000000000000111
*/
#include <bits/stdc++.h>
using namespace std;

int sizeofInt= sizeof(int)*8;
int table[70000];

int reverse(int);
int swap(int, int, int);
void precompute(void);
int reverseans(int, int, int);

int main() {
	// your code goes here
	int wordsize= sizeofInt/4;
	int bitmask=  (1<<(sizeofInt/4))-1;
	int num;
	cin>>num;
	int noOfBits= ceil(log2(num));
	precompute();
	cout<<reverseans(num, wordsize, bitmask);
	return 0;
}

void precompute(void){
	for (int i=1; i<= int(pow(2,(sizeofInt/4))-1); i++){
		table[i]= reverse(i);
		//cout<<i<<" "<<table[i]<<endl;
	}
}
int reverse(int num){
	int noOfBits= log2(num)+1;
	int i,j;
	for (i=0, j=noOfBits-1; i <= j ; i++,j--){
		num= swap(num,i,j);
	}
	return num;
}

int swap(int num, int i, int j){
	int bit_i= ((num>>i)&1);
	int bit_j= (num>>j)&1;
	if(bit_i != bit_j){
		//cout<<biti<<" "<<bitj<<endl;
		int bitmask= ((1<<i) | (1<<j));
		num ^= bitmask;
		//cout<<num<<endl;
	}
	//cout<<num<<endl;
	return num;
}
int reverseans(int num, int wordsize, int bitmask){
	if ( num < (1<<wordsize)){
	return table[num];
   }
	else if (num < (1<< 2*wordsize)){
	return table[num & bitmask]<<wordsize | table[(num >> wordsize)& bitmask];
  }
	else if (num < (1<< 3*wordsize)){
	return table[num&bitmask]<<2*wordsize | table[(num>>wordsize)&bitmask]<<wordsize | table[(num>>2*wordsize)&bitmask];
  }
	else{
	return table[num&bitmask] << (3*wordsize) | table[(num>>wordsize) & bitmask] << (2*wordsize) | table[(num>>2*wordsize) & bitmask] << wordsize | table[(num>>3*wordsize)&bitmask];
	}
}	