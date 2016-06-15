
/*  INCREMENT AN ARBITRARY PRECISION INTEGER
**  WAP that takes as input an array of digits encoding a decimal number D and updates the array to represent the number D+1.
**  Eg:- input- <1,2,9> output- <1,3,0> 
**  Better Solution
**  We operate directly on the array of digits.  
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> PlusOne(vector<int>);

int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
     	cin >> arr[i];
    }
	vector<int> v=PlusOne(arr);
	for(int i=0; i< v.size(); ++i){
		cout<<v[i]<<" ";
	}
	return 0;
}

vector<int> PlusOne(vector<int> arr){
	int carryin= 1, carryout= 0, i;
	int size= arr.size();
	for(i = size-1; i>0; --i){
	    int sum= arr[i]+ carryin;
	    carryout=0;
	    if (sum == 10){
	    	carryout= 1;
	    	sum= 0;
	    }
		arr[i]= sum;
		//cout<<i<<" "<<arr[i]<<endl;
		carryin= carryout;
		
	}
	if (carryout==1){
		arr[0]= 1;
		arr.push_back(0);
	}
	return arr;
}