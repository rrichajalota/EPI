/* Reversal of a singly linked list
** input- 3->4->6->9 output- 9->6>4->3
** Iterative Implementation. 
** Takes O(n) time and O(1) space.
*/

#include <iostream>
using namespace std;

struct node{
	int val;
	node* next;
} *head=NULL;

void insert(int key);
void display(node* h);
node* reverseList(node* h);

int main() {
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int key;
		cin>>key;
		insert(key);
	}
	display(head);
	node* rev= reverseList(head);
	display(rev);
	
	return 0;
}

void insert(int key){   // insertion at head
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
node* reverseList(node* h){
	if (h==NULL || h->next==NULL)
		return h;
	node *temp= h, *prev= NULL;
	while(temp->next!=NULL){
		node* t= temp->next;
		temp->next= prev;
		prev= temp;
		temp= t;
	}
	temp->next= prev;
	h= temp;
	return h;
}
