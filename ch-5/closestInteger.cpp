/* Find a closest integer with the same weight.
** Weight of a non-negative integer x is the number of 1s in its binary representation, eg, 92 - (1011100) has weight 4.
*/
#include <bits/stdc++.h>
using namespace std;

int closestInteger(int num);

int main() {
	// your code goes here
	int num;
	cin>>num;
	cout<< closestInteger(num);
	return 0;
}

int closestInteger(int num){
	try{
	int numUnsignedBits= sizeof(int)*8;
	for(int i= 0; i< numUnsignedBits-1 ; ++i){
		if (((num >>i) & 1) != ((num >> i+1) & 1)){
			int bitmask= 1 << i | 1 << (i+1);
			return num^bitmask;
		}
    }
    throw invalid_argument("e"); // if all bits are 0s or 1s, an exception will be thrown. 
    }
    catch (...){
    cout<<"All bits are 0 or 1";
    }
}