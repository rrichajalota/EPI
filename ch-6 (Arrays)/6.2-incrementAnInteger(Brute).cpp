
/*  INCREMENT AN ARBITRARY PRECISION INTEGER
**  WAP that takes as input an array of digits encoding a decimal number D and updates the array to represent the number D+1.
**  Eg:- input- <1,2,9> output- <1,3,0> 
**  Brute Force solution
**  Convert the array of integers into an equivalent integer. Then convert the integer back into array.  
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
	for(int i=0; i< n; ++i){
		cout<<v[i]<<" ";
	}
	return 0;
}

vector<int> PlusOne(vector<int> arr){
	int digit=0;
	int size= arr.size();
	//cout<<size<<endl;
	for (int i=0; i< size; ++i){
		digit= digit*10+ arr[i];
	}
	//cout<<digit<<endl;
	digit +=1;
	//cout<<digit<<endl;
	int divider= int(pow(10, size-1)); 
	int i=0;
	while (digit){
		arr[i]= digit/divider;
		digit = digit%divider;
		divider /= 10;
		++i;
	}
	//cout<<divider<<endl;
	while (divider>=1){
		arr[i]=0;
		++i;
		divider /= 10;
	}
	return arr;
}