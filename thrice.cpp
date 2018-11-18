#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int getSingle(int a[],int n)
{
	int result = 0,sum=0,i;
	for(i=0;i<32;i++)
	{
		sum=0;
		int x=(1<<i);
		for(int j=0;j<n;j++)
		{
			if(a[j]&x)	
			sum++;
		}
		if(sum%3)
		result|=x;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	 int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element with single occurrence is %d ",
            getSingle(arr, n));
    return 0;	

}

