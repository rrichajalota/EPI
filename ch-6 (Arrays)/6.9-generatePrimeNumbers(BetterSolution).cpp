/*  Enumerate all primes to n.
**  WAP that takes an integer argument and return all the primes between that 1 and that integer.
**  Eg:- input- 10 output- <2,3,5,7> 
**  Better Solution- For the input n (say 10), we create a boolean array of size n. If the ith index stores true, 
**  then i is potentially a prime. Initially, every number >= 2 is a candidate. When we determine a number is prime,
**  we add it to the result, and sieve out(remove) all the multiples of i from the array by writing false in their corresponding locations.
**  The time taken to sift out multiples of p is O(n/p). So, the overall time complexity is O(n/2 + n/3+ n/5 + ...) = O(nloglogn).
**  Space complexity- O(n) due to the storage of p.  
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
	vector<int> primeNumbers; // stores the primes 
	
	deque<bool> is_prime(num+1, true); 
	//is_prime[p] represents if p is prime or not. Initially, we set each value to true, except 0 and 1.
	is_prime[0]= is_prime[1]= false;
	
	for (int p=2; p<num; ++p){
		if (is_prime[p]){
			primeNumbers.push_back(p);
			// sieve out the multiples of p by writing false in the corresponding positions.
			for (int j= p; j<=num; j += p)
				is_prime[j]= false;
		}
	}
	return primeNumbers;
}