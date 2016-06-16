/* The Look-and-Say Problem
** The sequence starts with 1. Subsequent numbers are derived by describing the previous numbers in terms of consecutive digits.
** Eg. The sequence is 1 (1); one 1 (11); two 1s (21); one 2 then one 1 (1211); one 1 one 2 two 1s (111221) and so on.. 
** WAP that takes as input an integer n and returns the nth integer in the look-and-say sequence. Return the result as a string.
*/

#include <bits/stdc++.h>
using namespace std;

string lookAndSay(int num);

int main() {
	int num;
	cin>>num;
	cout<<lookAndSay(num);
	return 0;
}

string lookAndSay(int num){
	int i= 1;
	string s="1"; // stores the previous number 
	while(i<num){
		
		int j=0, size= s.length();
		string temp= "";   // stores new number  
		
		while( j < size ){
			int occur= 1;
			while(s[j]==s[j+1] && j<size){
				++occur, ++j;
			}
			temp += to_string(occur)+ s[j];
			++j;
		}
		
		++i;  
		s= temp; 
		//cout<<s<<endl;
	}
	return s;
}