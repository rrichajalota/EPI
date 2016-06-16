/* Test palindromicity.
** Define a palindrome to be a string which when all the nonalphanumeric are removed, reads the same front to back ignoring case.
** Eg. "A man, a plan, a canal, Panama" is a palindrome. "Ray is Ray" not a palindrome. 
** The solution below has a time complexity of O(n).
*/
#include <bits/stdc++.h>
using namespace std;

bool testPalindromicity(string &s);

int main() {

	string s;
	getline(cin, s);
	cout<<testPalindromicity(s);
		
	return 0;
}

bool testPalindromicity(string &s){

	for (int i=0; i< s.length(); i++){
		s[i]= tolower(s[i]);
	}
	int i=0, j= s.length()-1;
	while(i<=j){
		if((isalnum(s[i])) && (isalnum(s[j]))){
			if(s[i]==s[j]){
				++i; --j;
			}
			else{
				return false;
			}
		}
		else if(!(isalnum(s[i])))
			++i;
		else if(!(isalnum(s[j])))
			--j;
		else{
			++i; --j;
		}
	}
	return true;
}