// swap bits at indices i and j 
#include <iostream>
using namespace std;

void swap(long,int,int);
short parity(long);

int main() {
	// your code goes here
	long num;
	int i,j;
	cin>>num>>i>>j;
	swap(num,i,j);
	return 0;
}

void swap(long num, int i, int j){
    int numi= num&(1<<i);
    int numj= num&(1<<j);
    //set numj at i and numi at j
    int parity_i= parity(numi);
    int parity_j= parity(numj);
    if (parity_i==0){
        num= num&(~(~0 & (1<<j) ));
    }
    else if (parity_i==1){
        num= num|1<<j;
    }
    if (parity_j==0){
        num= num&(~(~0 & (1<<i) ));
    }
    else if (parity_j==1){
        num= num|1<<i;
    }
    
    cout<<num;
}

short parity(long num){
    int result=0;
    while(num){
        num= num&(num-1);
        result^= 1;
    }
    return result;
}