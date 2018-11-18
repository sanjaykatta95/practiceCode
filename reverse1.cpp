#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node
{
	int data;
	node *next;
};

void push(node **head,int data)
{
	node *temp= new node();
	temp->data=data;
	temp->next = *head;
	*head = temp;
}

void printList(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head= head->next;
	}
	return;
}

node *reverse(node *head)
{
	node *current=head,*prev=NULL,*next=NULL;
	while(current!=NULL&&current->data!=1)
	{
		next=current->next;
		current->next = prev;
		prev=current;
		current=next;
	}
	if(current==NULL)
	return prev;
	head->next = current;
	node *temp=current;
	current=current->next;
	temp->next = reverse(current);
	return prev;
}

int main()
{
	ios_base::sync_with_stdio(false);
	struct node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     // 5->6->4->1->7->2->1->9->44->53->1->6 
     push(&head, 6);
     push(&head, 1);
     push(&head, 53);
     push(&head, 44);
     push(&head, 9);
     push(&head, 1);
     push(&head, 2);
     push(&head, 7);
     push(&head, 1);           
     push(&head, 4);
     push(&head, 6);
     push(&head, 5);
 
     printf("\nGiven linked list \n");
     printList(head);
     cout<<endl;
     head = reverse(head);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
return 0;
}

