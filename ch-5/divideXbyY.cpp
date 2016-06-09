/* Compute x/y.
** Given two positive integers, compute their quotient, using only addition, subtraction and shifting operators.
*/
#include <bits/stdc++.h>
using namespace std;

int divide(int x, int y);

int main() {
	// your code goes here
	int x, y;
	cin>>x>>y;
	cout<< divide(x,y)<<endl;
	return 0;
}

int divide(int x, int y){
	int power= sizeof(int)*8; 
	int result= 0;
	long y_power= y<<power;
	while(x >=y){
		while (y_power > x){
			y_power >>= power;
			--power;
		}
		x -= y_power;
		result += 1<<power;
	}
	return result; 
	}