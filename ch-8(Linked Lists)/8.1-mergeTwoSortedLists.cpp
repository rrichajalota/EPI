/* Merge Two Sorted Lists
** WAP that takes two lists, assumed to be sorted and returns their merge.
** input- 2->5->7 and 4->6->9 output- 2->4->5->6->7->9
** Solution.
** Takes O(n+m) time, where n and m are the lengths of the two lists. O(1) space complexity
*/

#include <iostream>
using namespace std;

struct node{
	int val;
	node* next;
} *head1=NULL, *head2=NULL, *head3=NULL;

void createlist1(int num);
void createlist2(int num);
void insert(node* head,int key);
void display(node* head);
node* mergeTwoSortedLists(node* h1, node* h2);

int main() {
	int num;
	cin>>num;
	createlist1(num);
	cin>>num;
	createlist2(num);
	display(head1);
	display(head2);
	node* head=mergeTwoSortedLists(head1,head2);
	display(head);
	return 0;
}

void insert(node* head, int key){
	node* temp= new node;
	temp->val= key;
	temp->next= head;
	head= temp;
	cout<<head->val<<endl;
}

void display(node* head){
	node* temp= head;
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp= temp->next;
	}
	cout<<endl;
}

node* mergeTwoSortedLists(node* h1, node* h2){
	if (h1 ==NULL && h2==NULL)
		return NULL;
	if (h1 && !h2)
		return h1;
	if (!h1 && h2)
		return h2;
	
	node *temp1= h1, *temp2= h2;
	
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->val <= temp2->val){
			node *t= temp1->next;
			if(head3==NULL){
				head3= temp1;
				temp1->next=NULL;
			}
			else{
				node* temp= head3;
				while(temp->next != NULL)
					temp= temp->next;
				temp->next= temp1;
				temp1->next= NULL;
			}
			temp1= t;
		}
		else{
			node *t= temp2->next;
			if(head3==NULL){
				head3= temp2;
				temp2->next=NULL;
			}
			else{
				node* temp= head3;
				while(temp->next != NULL)
					temp= temp->next;
				temp->next= temp2;
				temp2->next= NULL;
			}
			temp2= t;
		}
	}
	if (temp1 != NULL && temp2==NULL){
		node* temp= head3;
		while(temp->next != NULL)
			temp= temp->next;
		temp->next= temp1;
	}
	else if (temp1==NULL && temp2 != NULL){
		node* temp= head3;
		while(temp->next != NULL)
			temp= temp->next;
		temp->next= temp2;
	}
	return head3;
}

void createlist1(int num){   
  int data;
  
  for(int i=0; i<num; i++){
    cin>>data; //value of the node
    node* temp= new node;
    temp->val= data;
    temp->next= NULL;
    
    if (head1== NULL)
      head1=temp;
    
    else{
      node* temp1= head1;
      
      while(temp1->next!=NULL)
        temp1=temp1->next;
      
      temp1->next=temp;
    }
  }     
}

void createlist2(int num){   
  int data;
  
  for(int i=0; i<num; i++){
    cin>>data; //value of the node
    node* temp= new node;
    temp->val= data;
    temp->next= NULL;
    
    if (head2== NULL)
      head2=temp;
    
    else{
      node* temp2= head2;
      
      while(temp2->next!=NULL)
        temp2=temp2->next;
      
      temp2->next=temp;
    }
  }     
}
