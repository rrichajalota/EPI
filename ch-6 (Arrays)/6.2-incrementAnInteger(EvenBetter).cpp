/*  INCREMENT AN ARBITRARY PRECISION INTEGER
**  WAP that takes as input an array of digits encoding a decimal number D and updates the array to represent the number D+1.
**  Eg:- input- <1,2,9> output- <1,3,0> 
**  Even Better Solution- Just look at it's beauty! 
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
	++arr.back();  // incremented the Least Significant digit of the number
	// worst case- the digit is 9. so 9+1 = 10.
	for (int i= arr.size()-1; i >0 && arr[i]== 10; --i){
		arr[i]= 0;
		++arr[i-1];
		}
	if (arr[0] == 10){
	// if the most significant digit has a carry-out, we need an additional digit 
		arr[0]= 1;
		arr.push_back(0);
	}
	return arr;
}