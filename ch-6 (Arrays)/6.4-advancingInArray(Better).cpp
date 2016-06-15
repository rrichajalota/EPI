/*Advancing through an Array
** WAP that takes an array of n integers, where A[i] denotes the maximum we can advance from index i, and returns whether it's possible to 
** advance to the last index starting from the beginning of the array. 
** Better Solution. 
** The furthest we can advance to from index i is (i + A[i]).
** if A= <3,3,1,0,2,0,1>, we iteratively compute the furthest we can advance to as 0,3,4,4,4,6,6,7. It reaches the last index. 
** This solution is robust w.r.t the negative entries as well. 
** Time Complexity- O(n). Space complexity- O(1).
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
	int furthest_reach_so_far=0, last_index= max_advance_steps.size()-1;
	for (int i=0; i<= furthest_reach_so_far && furthest_reach_so_far< last_index; ++i){
		max(furthest_reach_so_far, max_advance_steps[i]+1);
	}
	return furthest_reach_so_far >= last_index;
}