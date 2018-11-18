#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int height(node *root)
{
	if(root==NULL)
	return 0;
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(lheight>rheight)
		return lheight+1;
		else return rheight+1;
	}
}

void printGivenLevel(node *root,int level)
{
	if(root==NULL)
	return;
	if(level==1)
	cout<<root->data<<" ";
	else if(level>1)
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

void printLevelOrder(node *root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
		printGivenLevel(root,i);
}

void printLevelOrderq(node *root)
{
	if(root == NULL)
	return;
	queue<node*> q;
	while(root)
	{
		cout<<root->data<<" ";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
		root=q.front();
		q.pop();	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	node *root 		  = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    
    printLevelOrderq(root);
 
    return 0;
}

