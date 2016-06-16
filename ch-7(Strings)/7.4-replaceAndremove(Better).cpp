/* WAP which takes as input an array of characters and removes each 'b' and replaces each 'a' by 2 'd's. Along with the array, we are provided 
** an integer-vaalued size, which denotes the number of entries in the array.
** E.g if input- <a, b, a, c> and size- 4, output- <d, d, d, d, c>
** Better Approach.
** We apply two iterations. In first iteration, we remove the 'b's and count the number of 'a's. Then we update the final size of the array 
** which is the size after having 'b's removed + the number of 'a's. Now, suppose after first iteration we have the array <a,c,a,a,_,_,_>.
** We work our way backwards now (from right to left). For the first 'a', updated array- <a,c,a,a,_,d,d,>. For the next 'a'- <a,c,a,d,d,d,d>.
** For 'c'- <a,c,c,d,d,d,d>. Finally for 'a'-<d,d,c,,d,d,d,d>. 
** Time complexity for each iteration-O(n), so total time complexity- O(n). 
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
int count_a = 0, count_b=0, writeIndex=0;

	for (int i=0; i<A.size(); ++i){
		if(A[i] != 'b'){
			A[writeIndex++]= A[i];
		}
		if (A[i]=='a'){
			++count_a;
		}
		else if (A[i]=='b'){
			++count_b;
		}
	}
    A.resize(size-count_b);
    
    size= A.size()+ count_a;
    A.resize(size); 
	int currentIndex= writeIndex-1;
	writeIndex= A.size()-1;
	
	while(currentIndex>=0){
		if(A[currentIndex]=='a'){
			A[writeIndex--]= 'd';
			A[writeIndex--]= 'd';
			--currentIndex;
		}
		else{
			A[writeIndex--]=A[currentIndex];
			--currentIndex;
		}
	}
}