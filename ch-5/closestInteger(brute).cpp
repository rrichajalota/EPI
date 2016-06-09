/* Find a closest integer with the same weight.
** Weight of a non-negative integer x is the number of 1s in its binary representation, eg, 92 - (1011100) has weight 4.
*/
#include <bits/stdc++.h>
using namespace std;

int checkWeight(int num);
int closestInteger(int num);

int main() {
	// your code goes here
	int num;
	cin>>num;
	cout<< closestInteger(num);
	return 0;
}

int checkWeight(int num){
	int count=0;
	while(num){
		num= num&(num-1);
		count++;
	}
	return count;
}

int closestInteger(int num){
	int weight_num= checkWeight(num);
	int diff=1;
	while(true){
		if (weight_num != checkWeight(num-diff)){
			if (weight_num != checkWeight(num+diff))
				diff++;
			else return (num+diff);
		}
		else return (num-diff);
	}
}