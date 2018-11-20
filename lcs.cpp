#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int lcs(char x[],char y[],int m,int n)
{
	int dp[m+1][n+1],i,j;
//	memset(dp,0,sizeof(dp));
	
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(x[i-1]==y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  cout << "testing mergin"<<endl;




 
return 0;
}

