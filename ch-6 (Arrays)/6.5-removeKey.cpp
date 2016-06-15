/* Delete all occurences of a key from an array and return the number of remaining elements. 
** There are no requirements as to the values stored beyond the last valid element.
** Brute force solution. 
** time complexity- O(n^2)
** space complexity- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> removeKey(vector<int> v, int key);

int main() {
	// your code goes here
	int n, key;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
     	cin >> v[i];
    }
    cin>>key; // value to be removed 
	v= removeKey(v,key);
	for(int i=0; i< v.size(); ++i){
		cout<<v[i]<<" ";
	}
	return 0;
}


vector<int> removeKey(vector<int> v, int key){
	int i=0, count=0;
	int last_index= v.size()-1;
	while( i <= last_index){
		if (v[i] == key){
			count++;
			--last_index;
			for (int j= i; j<= v.size()-1; j++)
				v[j]= v[j+1];
		}
		if (v[i] != key){
		   ++i;
		}
	}
	int size= v.size()-count;
	cout<<size<<endl;
	return v;
}