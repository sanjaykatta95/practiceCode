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

node *minValueNode(node *root)
{
	if(root == NULL)
	return root;
	while(root->left!=NULL)
	root= root->left;
	return root;
}

node *deleteNode(node *root,int data)
{
	if(root == NULL)
	return root;
	if(data < root->data)
	root->left = deleteNode(root->left,data);
	else if(data>root->data)
	root->right = deleteNode(root->right,data);
	else
	{
		if(root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			node *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
}

void inorder(node *root)
{
	if(root == NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node *insert(node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	if(data<root->data)
		root->left = insert(root->left,data);
	if(data>root->data)
		root->right = insert(root->right,data);
	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
return 0;
}

