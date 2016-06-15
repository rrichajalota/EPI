// Remove duplicates from a sorted array.

#include <bits/stdc++.h>
using namespace std;

int deleteDuplicatesFromSortedArray(vector<int> &v);

int main() {
	// your code goes here
	int n, key;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
     	cin >> v[i];
    }
    cin>>key; // value to be removed 
	int size= deleteDuplicatesFromSortedArray(v);
	for(int i=0; i< size; ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<size<<endl;
	return 0;
}


int deleteDuplicatesFromSortedArray(vector<int> &v){
	int writeIndex=1;
	for( int i= 1; i < v.size() ; ++i ){
		if (v[i-1] < v[i]){
			v[writeIndex++] = v[i];
		}
	}
    return writeIndex;
}
	