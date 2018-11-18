#include <bits/stdc++.h>
using namespace std;
#define long long int ll

void swap(int *a,int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int partition(int a[],int l,int h)
{
	if(l<h)
	{
		int i=l,j,pivot=a[h];
		for(j=l;j<h;j++)
		{
			if(a[j]<pivot)
			{
				swap(&a[i],&a[j]);
				i++;	
			}		
		}		
		swap(&a[i],&a[h]);
		return i;
	}	
	return -1;
}

int kthSmallest(int a[],int l,int r,int k)
{
	if(k>0&&k<=r-l+1)
	{
		int pos = partition(a,l,r);
		if(k==pos-l+1)
		return a[pos];
		else if(k<pos-l+1)
		return kthSmallest(a,l,pos-1,k);
		else return kthSmallest(a,pos+1,r,k-(pos-l+1));
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	
 	int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);
    return 0;
}

