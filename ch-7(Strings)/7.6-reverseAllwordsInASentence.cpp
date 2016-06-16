/* Reverse all the words in a sentence. Given a set of words separted by whitespace, transform it to a string in which the 
** words appear in reverse order. Eg. If input is "ALice likes Bob", output will be "Bob likes Alice".
** Solution.
** Just reverse the string first to get all the words in their correct relative order. Then, reverse the words. 
** Time complexity of the solution is O(n). If strings are mutable, we can perform the computation in-place, i.e. with O(1) space complexity.
** If the strings cannot be changed, the additional space complexity is O(n), where we need to create a new string of length n.
*/ 

#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &s);

int main() {
	string s;
	getline(cin, s);
	reverseWords(s);
	cout<<s;
	return 0;
}

void reverseWords(string &s){
	reverse(s.begin(),s.end());
	int i=0;
	while(i< s.length()){
		string word= "";
		int start=i, wordlen= 0;
		while(s[i] != ' ' && i < s.length()){
			word += s[i];
			++i, ++wordlen;
		}
		//cout<<word<<endl;
		reverse(word.begin(), word.end());
		s.replace(s.begin()+start, s.begin()+start+wordlen, word);
		++i;
	}
}