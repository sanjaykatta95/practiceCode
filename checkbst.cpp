#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node
{
	int data;
	node *left,*right;
}node;

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool isBSTUtil(node *root,int min,int max)
{
	if(root == NULL)
	return true;
	if(root->data<min||root->data>max)
	return false;
	return isBSTUtil(root->left,min,root->data-1)&&isBSTUtil(root->right,root->data+1,max);
}

bool isBST(node *root)
{
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main()
{
	ios_base::sync_with_stdio(false);
	struct node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
 
    if (isBST(root))
        cout << "Is BST b";
    else
        cout << "Not a BST";
 
return 0;
}

