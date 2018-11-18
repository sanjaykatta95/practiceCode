#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node
{
	char data;
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

int search(char in[],char data,int min,int max)
{
	for(int i=min;i<=max;i++)
	if(in[i]==data)
	return i;
	return -1;
}

node *buildTree(char in[],char pre[],int inStart,int inEnd)
{
	static int preIndex = 0;
	if(inStart>inEnd)
	return NULL;
	node *temp = newNode(pre[preIndex++]);
	int inIndex = search(in,temp->data,inStart,inEnd);
	if(inIndex ==-1)
	return NULL;
	temp->left = buildTree(in,pre,inStart,inIndex-1);
	temp->right = buildTree(in,pre,inIndex+1,inEnd);
	return temp;
}

void printInorder(node *root)
{
	if(root ==NULL)
	return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
return 0;
}

