/* Palindrome of a Number.
A Palindrome is a string that reads the same forwards and backwards,eg, "redivider". In this question, we need to check if a decimal representation of an integer is a palindrome string.
 */

#include <bits/stdc++.h>
using namespace std;

bool palindrome(int x);

int main() {
	// your code goes here
	int num;
	cin>>num;
	cout<<palindrome(num)<<endl;
	return 0;
}

bool palindrome(int num){
	if (num < 0)
		return false;
	else if (num==0)
		return true;
	else{
		int noOfDigits= ceil(log10(num));
		int mask_msd= int(pow(10, noOfDigits-1));
		for (int i= 0; i < noOfDigits/2; i++){
			int msd= num/mask_msd;
			int lsd= num % 10;
			if ( msd != lsd)
				return false;
			num= num % mask_msd;   // remove msd
			num= num/10;		   // remove lsd
			mask_msd /= 100;
		}
		return true;
   	}
}