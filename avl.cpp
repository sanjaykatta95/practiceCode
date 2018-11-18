#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node 
{
	int key,height;
	node *left,*right;
}node;

node *newNode(int key)
{
	node *temp = new node();
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	temp->height=0;
	return temp;
}

int max(int a,int b)
{
	if(a>b)
	return a;
	else return b;	
}

int height(node *root)
{
	if(root == NULL)
	return 0;
	else return root->height;
}

int getBalance(node *root)
{
	if(root==NULL)
	return 0;
	else return height(root->left)-height(root->right);
}

node *rotateLeft(node *z)
{
	node *y=z->left;
	node *t3=y->left;
	y->right = z;
	z->left = t3;
	y->height = 1+max(height(y->left),height(y->right));
	z->height = 1+max(height(z->left),height(z->right));
	return y;
}

node *rotateRight(node *z)
{
	node *y=z->right;
	node *t2=y->left;
	y->left=z;
	z->right = t2;
	y->height = 1+max(height(y->left),height(y->right));
	z->height = 1+max(height(z->left),height(z->right));
	return y;
}

node *insert(node *root,int key)
{
	if(root==NULL)
	return newNode(key);
	if(key<root->key)
	root->left = insert(root->left,key);
	else if(key>root->key)
	root->right = insert(root->right,key);
	else return root;
	
	root->height=1+max(height(root->left),height(root->right));
	
	int balance = getBalance(root);
	
	//left left case
	if(balance > 1 && key<root->left->key)
	return rotateRight(root);
	
	//right right case
	if(balance<-1 && key>root->right->key)
	return rotateLeft(root);
	
	//left right case
	if(balance >1 && key > root->left->key)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	
	//right left case
	if(balance<-1&&key<root->right->key)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}
	
	return root;
}

void preOrder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	struct node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}

