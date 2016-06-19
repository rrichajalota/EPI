/* Reverse a single sublist 
** The program takes as input a singly linked list and two integers s and f. 
** Eg. input- 1->2->3->4->5 ; s = 2 ; f = 4
** 	  output- 1->4->3->2->5
*/

#include <iostream>
using namespace std;

struct node{
	int val;
	node* next;
} *head=NULL;

void insert(int key);
void display(node* h);
node* reverseSublist(node* h, int s, int f);

int main() {
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int key;
		cin>>key;
		insert(key);
	}
	int s, f;
	cin>>s>>f;
	display(head);
	node* rev= reverseSublist(head,s,f);
	display(rev);
	
	return 0;
}

void insert(int key){
	node* temp= new node;
	temp->val= key;
	temp->next= head;
	head= temp;
}
void display(node* h){
	node* temp= h;
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp= temp->next;
	}
	cout<<endl;
}
node* reverseSublist(node* h, int s, int f){
	if (h==NULL || h->next==NULL || s > f)
		return h;
	node* temp= h, *prev=NULL;
	int i=1;
	while(temp!=NULL && i<s){
		prev= temp;
		temp=temp->next;
		++i;
	}
	
	node *next= temp->next, *after_next=NULL;
	
	while(next != NULL && s<f){
		after_next= next->next;
		next->next= temp;
		temp= next;
		//cout<<temp->val<<endl;
		next= after_next;
		++s;
	}
	
	if (prev==NULL){
		node *S= h; //sth node
		h= temp;
		S->next= next;
	}
	else{
		node *S= prev->next; //the sth node
		S->next= next;
		prev->next= temp;
	}
	return h;
}
