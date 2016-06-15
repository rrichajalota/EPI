/* Advancing through an Array
** WAP that takes an array of n integers, where A[i] denotes the maximum we can advance from index i, and returns whether it's possible to 
** advance to the last index starting from the beginning of the array. 
** Brute force solution. 
** Check iteratively the best next step that should be taken at index i. 
** time complexity-  space complexity- O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool canReachEnd(vector<int>);

int main() {
	// your code goes here
	int n;
    cin >> n;
    vector<int> max_advance_steps(n);
    for(int i = 0; i < n; i++){
     	cin >> max_advance_steps[i];
    }
	cout<<canReachEnd(max_advance_steps)<<endl;
	return 0;
}

bool canReachEnd(vector<int> max_advance_steps){
	int i=0, size= max_advance_steps.size();
	while ( i != size-1 ){
		int furthest=0; int incrementBy= 0;
		for (int j= max_advance_steps[i]; j > 0;  --j){
			if ( i+j <= size-1 && max_advance_steps[i+j] != 0){
				int step= i+j;
				if (max_advance_steps[step] > furthest){
					furthest= max_advance_steps[step];
					incrementBy= step;
				}
			}
		}
		if (furthest==0)
			return false;
		else {
		i= incrementBy;
		//cout<<i<<endl;
		}
	}
	return true;
	
}