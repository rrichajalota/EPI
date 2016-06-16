/* WAP which takes as input an array of characters and removes each 'b' and replaces each 'a' by 2 'd's. Along with the array, we are provided 
** an integer-vaalued size, which denotes the number of entries in the array.
** E.g if input- <a, b, a, c> and size- 4, output- <d, d, d, d, c>
** Brute Force Approach.
** Use insertion and deletion (erase) functions to insert and erase an element from a position. Each insertion and deletion will have 
** a time comlpexity of O(n). Therefore, for n elements in an array, time complexity would be O(n^2).
*/

#include <bits/stdc++.h>
using namespace std;

void removeAndReplace(vector<char> &A, int size);

int main() {
	
	int size;
	cin>>size;
	vector<char> A(size);
	for (int i= 0; i< size; i++)
		cin>>A[i];
	removeAndReplace(A,size);
	for (int i= 0; i< A.size(); i++)
		cout<<A[i]<<" ";
	return 0;
}

void removeAndReplace(vector<char> &A, int size){

	for(int i=0; i< A.size(); i++){
		if(A[i]== 'a'){
			A[i]= 'd';
			A.insert(A.begin()+i, 'd');
		}
		else if(A[i] =='b'){
			A.erase(A.begin()+i); //removes the element at index i, shifts the elements from i+1 to A.size()-1 to the left
			--i;                 //The element which was at i+1 is now at i. So to check its value, decrement i. 
		}
	}
}