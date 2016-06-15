/*  Permute the elements of an array
**  A permutation can be specified by an array P, where P[i] represents the location of the element at i in permutation.
**	Eg. The array <2,0,1,3> represents permutation that maps the element at index 0 to 2, element at 1 to 0, element at 2 to 1 
**	and 3 remains unchanged. If V= <3,5,6,7> and P= <2,0,1,3>, resulting array- <5,6,3,7>.
**	Alternate Solution. 
**	If the use of sign bits is not allowed. 
*/
 
#include <bits/stdc++.h>
using namespace std;

void applyPermutation(vector<int> &V, vector<int> &permutation);

int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<int> V(n);
    vector<int> permutation(n);
    for(int i = 0; i < n; i++){
     	cin >> V[i];
    }
    for(int i = 0; i < n; i++){
     	cin >> permutation[i];
    }
	applyPermutation(V, permutation);
	for(int i=0; i< V.size(); ++i){
		cout<<V[i]<<" ";
	}
}

void applyPermutation(vector<int> &V, vector<int> &permutation){
	for (int i= 0; i< V.size(); ++i){
		bool is_min= true;
		int j= permutation[i];
		while( i!=j ){
			if(j < i){
				is_min= false;
				break;
			}
			j= permutation[j];
	}
}