/*  Enumerate all primes to n.
**  WAP that takes an integer argument and return all the primes between that 1 and that integer.
**  Eg:- input- 10 output- <2,3,5,7> 
**  Brute Force Solution- Iterate over each number to check if it's prime and add it in an array.
**  To check if a number i is prime, we divide it by each integer from 2 to the square root of i. 
**  Each iteration takes O(n^0.5). Thus n iterations take O(n^1.5). 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> primeNumberGenerator(int num);

int main() {
	// your code goes here
	int num;
    cin >> num;
	vector<int> primeNumbers= primeNumberGenerator(num);
	for(int i=0; i< primeNumbers.size(); ++i){
		cout<<primeNumbers[i]<<" ";
	}
	return 0;
}

vector<int> primeNumberGenerator(int num){
	vector<int> primeNumbers;
	if (num== 0 || num==1)
		return primeNumbers;
	if (num == 2){
		primeNumbers.push_back(2);
		return primeNumbers;
	}
	int check=0;
	primeNumbers.push_back(2);
	for (int i=3; i<= num; i++){
		check=0;
		for ( int j=2; j<= sqrt(i); j++){
			if (i % j == 0){
				check= 1;
				break;
			}
		}
		if (check==0){
			primeNumbers.push_back(i);
		}
	}
	return primeNumbers;
}