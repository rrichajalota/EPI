/*  Permute the elements of an array
**  A permutation can be specified by an array P, where P[i] represents the location of the element at i in permutation.
**	Eg. The array <2,0,1,3> represents permutation that maps the element at index 0 to 2, element at 1 to 0, element at 2 to 1 
**	and 3 remains unchanged. If V= <3,5,6,7> and P= <2,0,1,3>, resulting array- <5,6,3,7>.
**	Brute Force Solution. Takes O(n) time and O(n) space.
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
	vector<int> temp(V.size());
	for (int i= 0; i < V.size(); i++){
		temp[permutation[i]]= V[i];
		}
	for (int i= 0; i < V.size(); i++)
		V[i]= temp[i];
}