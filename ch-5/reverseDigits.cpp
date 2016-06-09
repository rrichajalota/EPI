// reverse the digits of a number. eg. if input= 42, output= 24
#include <bits/stdc++.h>
using namespace std;

int reverseDigit(int x);

int main() {
	// your code goes here
	int x;
	cin>>x;
	cout<<reverseDigit(x)<<endl;
	return 0;
}

int reverseDigit(int x){
    bool is_negative= x < 0;
    x= abs(x);
	int quotient=0, rem=0, rev=0;
	while(x){
		rem= x%10;
		x= x/10;
		rev= rev*10+rem;
	}
	return is_negative ? -rev: rev;
}