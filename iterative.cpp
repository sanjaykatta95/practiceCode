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

void postorder(node *root)
{
	if(root==NULL)
	return;
	stack<node *> st1,st2;
	st1.push(root);
	while(!st1.empty())
	{
		node *temp = st1.top();
		st1.pop();
		st2.push(temp);
		if(temp->left)
		st1.push(temp->left);
		if(temp->right)
		st1.push(temp->right);
	}
	while(!st2.empty())
	{
		node *temp = st2.top();
		st2.pop();
		cout<<temp->data<<" ";
	}
	cout<<endl;
}

void preorder(node *root)
{
	if(root == NULL)
	return;
	stack<node *> st;
	st.push(root);
	while(!st.empty())
	{
		node *current = st.top();
		st.pop();
		cout<<current->data<<" ";
		if(current->right)
			st.push(current->right);
		if(current->left)
			st.push(current->left);
	}
	cout<<endl;
}

void inorder(node *root)
{
	if(root == NULL)
	return;
	stack<node *> st;
	node *current = root;
	bool done = false;
	while(!done)
	{
		if(current)
		{
			st.push(current);
			current = current->left;
		}
		else
		{
			if(!st.empty())
			{
				current = st.top();
				st.pop();
				cout<<current->data<<" ";
				current = current ->right;
			}
			else done = true;
		}
	}
	cout<<endl;
}

void postorder2(node *root)
{
	if(root ==NULL)
	return;
	stack<node *> st;
	do
	{
		while(root)
		{
			if(root->right)
			st.push(root->right);
			st.push(root);
			root = root->left;
		}
		root = st.top();
		st.pop();
		if(root->right&&st.top() == root->right)
		{
			st.pop();
			st.push(root);
			root= root->right;
		}
		else
		{
			cout<<root->data<<" ";
			root = NULL;
		}
	}while(!st.empty());
	cout<<endl;
}

int height(node *root)
{
	if(root==NULL)
	return 0;
	else 
		return 1+max(height(root->left),height(root->right));
}

void printGivenLevel(node *root,int level)
{
	if(root==NULL)
	return;
	if(level==1)
	cout<<root->data<<" ";
	else
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

void levelOrder(node *root)
{
	if(root==NULL)
	return;
	int h=height(root),i;
	for(i=1;i<=h;i++)
	printGivenLevel(root,i);
}

void levelOrder2(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
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
    inorder(root);
    getchar();
    preorder(root);
    getchar();
    postorder(root);
    getchar();
    postorder2(root);
    getchar();
    levelOrder2(root);
    return 0;
}

