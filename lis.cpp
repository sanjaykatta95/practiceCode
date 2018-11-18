#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int lis(int a[],int n)
{
	int lis[n]={1},i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i]&&lis[i]<lis[j]+1)
			lis[i]=lis[j]+1;
		}
	}
	int max_value=INT_MIN;
	for(i=0;i<n;i++)
	if(lis[i]>max_value)
	max_value=lis[i];
	return max_value;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}

