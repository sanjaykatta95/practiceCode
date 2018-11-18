#include <bits/stdc++.h>
using namespace std;
#define long long int ll
#define ALPHA_SIZE 26

typedef struct
{
	bool isEOW;
	node *next[ALPHA_SIZE];
}node;

int showMenu()
{
    int choice;
    printf("\n\tMenu");
    printf("\n\t====");
    printf("\n\t1. Insert Word");
    printf("\n\t2. Auto Suggest word");
    printf("\n\t3. Print All words");
    printf("\n\t4. Exit");
    printf("\n\tEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

node *createNode()
{
	node *root = new node();
	root->isEOW = false;
	for(int i=0;i<ALPHA_SIZE;i++)
	root->next[i] = NULL;
	return root;
}

void insertWord(node *root,char word[])
{
	int i,idx;
	for(i=0;i<strlen(word);i++)
	{
		idx = word[i]-'a';
		if(root->next[idx]==NULL)
		{
			root->next[idx] = createNode();
		}
		root=root->next[idx];
	}
	root->isEOW = true;
}

void printAllWords(node *root,char prefix[])
{
	int i;
	if(root->isEOW==true)
		printf("\n\t%s",prefix);
	for(i=0;i<ALPHA_SIZE;i++)
	{
		if(root->next[i]!=NULL)
		{
			char c= i+'a';
			char newPrefix[200];
			sprintf(newPrefix,"%s%c",prefix,c);
			printAllWords(root->next[i],newPrefix);
		}
	}
}

void autoSuggest(node *root,char prefix[])
{
	int i;
	for(i=0;prefix[i]!='\0';i++)
	{
		idx = prefix[i]-'a';
		root = root->next[idx];
		if(root == NULL)
		{
			cout<<"there are no words"<<endl;
			return;
		}
	}
	printAllWords(root,prefix);
}

int main()
{
    Node *root = createNode();
    int choice;
    char word[200];

    FILE *fp = fopen("dictionary.txt", "r");
    if(fp==NULL)
    {
        printf("\ndictionary.txt MUST be there in current directory");
        return;
    }
    while(!feof(fp))
    {
        fscanf(fp, "%s", word);
        insertWord(root, word);
    }
    fclose(fp);

    while(1)
    {
        choice = showMenu();
        switch(choice)
        {
        case 1:
            printf("\n\tEnter word : ");
            scanf("%s",word);
            insertWord(root,word);
            break;
        case 2:
            printf("\n\tEnter prefix : ");
            scanf("%s",word);
            autoSuggest(root,word);
            break;
        case 3:
            printAllWords(root, "");
            break;
        case 4:
            return 0;
        default:
            printf("\n\t Wrong choice, Enter Again");
        }
    }
    return 0;
}
