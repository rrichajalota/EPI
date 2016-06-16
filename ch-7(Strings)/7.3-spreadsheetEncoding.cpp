/* Implement a function that converts a spreadsheet column id to the corresponding integer with "A" corresponding to 1.
** Eg. "D" returns 4, "AA" returns 27, "ZZ" returns 702, "AAA" returns 703.
** Solution.
** We follow the same algorithm as we would use for converting a base-26 number to the corresponding integer.
** ZZ = 26^26 + 26, AB= 26*1+ 2.
** time complexity- O(n) where n is the length of the string.
*/ 

#include <bits/stdc++.h>
using namespace std;

int spreadsheetEncoding(string &s);

int main() {
	// your code goes here
	string s;
	cin>>s;
	cout<<spreadsheetEncoding(s);
	return 0;
}

int spreadsheetEncoding(string &s){
	int result=0;
	for( int i= 0; i<s.length(); ++i){
	result = result*26+(s[i]-'A'+1);
	}
	return result;
}