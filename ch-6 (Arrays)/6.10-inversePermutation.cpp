/*  Compute inverse permutation.
**  Given an array A of integers representing a permutation, update A to represent the inverse permutation using only
**	constant additional space.
**	To find the inverse permutation, fix the first element in the cycle and write the remaining elements in reverse order.
**	Eg. inverse of <1,2,3,4,5> -> <1,5,4,3,2>
*/
 
#include <bits/stdc++.h>
using namespace std;

void inversePermutation(vector<int> &V);

int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<int> V(n);
    for(int i = 0; i < n; i++){
     	cin >> V[i];
    }
    
	inversePermutation(V);
	for(int i=0; i< V.size(); ++i){
		cout<<V[i]<<" ";
	}
}

void inversePermutation(vector<int> &V){
	int swapwith= V.size()-1;
	for (int i= 1; i< V.size()/2; ++i){ // Keep the first element at index 0 fixed.
		swap(V[i], V[swapwith--]);
	}
}