/* Delete all occurences of a key from an array and return the number of remaining elements. 
** There are no requirements as to the values stored beyond the last valid element.
** Optimized solution. 
** Our algorithm skips over elements not equal to key, and tracks the location the next element not equal to key should be written to.
** time complexity- O(n)
** space complexity- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int removeKey(vector<int> &v, int key);

int main() {
	// your code goes here
	int n, key;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
     	cin >> v[i];
    }
    cin>>key; // value to be removed 
	int size=removeKey(v,key);
	for(int i=0; i< size; ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<size<<endl;
	return 0;
}


int removeKey(vector<int> &v, int key){
	int writeIndex=0;
	for( int i= 0; i < v.size() ; ++i ){
		if (v[i] != key){
			v[writeIndex++] = v[i];
		}
	}
    return writeIndex;
}
	