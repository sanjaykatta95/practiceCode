#include <bits/stdc++.h>
using namespace std;
#define long long int ll
#define N 4

bool isSafe(int maze[N][N],int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<N&&maze[x][y]==1)
	return true;
	else return false;
}

bool solveMazeUtil(int **sol,int maze[N][N],int x,int y)
{
	if(x==N-1&&y==N-1)
	{
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y))
	{
		sol[x][y]=1;
		if(solveMazeUtil(sol,maze,x+1,y)||solveMazeUtil(sol,maze,x,y+1))
		return true;
		sol[x][y]=0;
		return false;
	}
}

int** solveMaze(int maze[N][N])
{
//	int *sol[N],i,j;
//	for(i=0;i<N;i++)
//	sol[i]=(int*)calloc(N,sizeof(int));
//	for(i=0;i<N;i++)
//	{
//		for(j=0;j<N;j++)
//	cout<<sol[i][j]<<" ";
//	cout<<endl;
//	}

//	int **sol = (int **)calloc(N,sizeof(int *)),i,j;
//	for(i=0;i<N;i++)
//	sol[i]=(int *)calloc(N,sizeof(int));
	int **sol=new int*[N],i,j;
	for(i=0;i<N;i++)
	sol[i]=new int[N];
//	memset(sol,-1,sizeof(int)*4*4);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		sol[i][j]=0;
	}
	if(!solveMazeUtil(sol,maze,0,0))
	{
		cout<<"solution does not exist"<<endl;
		return NULL;
	}
	return sol;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
 	int **sol=(int **)malloc(sizeof(int)*N);
 	for(int i=0;i<N;i++)
 	sol[i]=new int[N];
    sol = solveMaze(maze);
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	cout<<sol[i][j]<<" ";
    	cout<<endl;
	}
    return 0;
return 0;
}

