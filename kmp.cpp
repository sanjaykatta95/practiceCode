#include <bits/stdc++.h>
using namespace std;
#define long long int ll

void computeLPSarray(char *pat,int m,int *lps)
{
	int i=1,j=0;
	lps[0]=0;
	while(i<m)
	{
		if(pat[i]==pat[j])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			j=lps[j-1];
			else 
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMPSearch(char *pat,char *txt)
{
	int m=strlen(pat),n=strlen(txt),i=0,j=0;
	int *lps=new int[m];
	computeLPSarray(pat,m,lps);
	while(i<n)
	{
		if(pat[j]==txt[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"pattern found at index : "<<j<<endl;
			j=lps[j-1];	
		}
		else if(i<n&&pat[j]!=txt[i])
		{
			if(j!=0)
			j=lps[j-1];
			else i++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}

