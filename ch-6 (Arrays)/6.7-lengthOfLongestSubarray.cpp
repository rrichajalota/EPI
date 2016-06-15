// WAP that takes an array of integers and finds the length of the longest subarray all of whose entries are equal.

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayofEqualEntries(vector<int> v);

int main() {
	// your code goes here
	int n, key;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++){
     	cin >> v[i];
    }
    
	int length= longestSubarrayofEqualEntries(v);
	cout<<length<<endl;
	return 0;
}


int longestSubarrayofEqualEntries(vector<int> v){

	 if( v.empty() )
	 	return 0;
	 	
	 int maxSubarray= 1, subarray=1;

	 for(int i=0; i< v.size() ; i++){
	 	if (v[i]== v[i+1]){
	 		++subarray;
	 		if (maxSubarray < subarray)
	 			maxSubarray= subarray;
	 	}
	 	else subarray= 1;
	 }
	 return maxSubarray;
}
	