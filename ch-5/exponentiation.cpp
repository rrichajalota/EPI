/* compute x^y
** WAP that takes a double x and integer y and returns x^y. 
*/

#include <bits/stdc++.h>
using namespace std;

double exponentiation(double x, int y);

int main() {
	// your code goes here
	double x; int y;
	cin>>x>>y;
	cout<<exponentiation(x,y)<<endl;
	return 0;
}

double exponentiation(double x, int y){
	 double result = 1.0;
	 int power = y;
	 if (y < 0){			// if y is negative
	 	x = 1.0/x;
	 	power = -power;
	 	}
	 while (power){
	 	if ( power & 1){
	 		result *= x;
	 	}
	    x *= x;
	    power >>= 1;
	 }
	 return result;
	}