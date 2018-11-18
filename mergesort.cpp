#include <bits/stdc++.h>
using namespace std;
#define long long int ll

void merge(int a[],int l,int m,int r)
{
	int i=0,j=0,k,n1=m-l+1,n2=r-m;
	int left[n1],right[n2];
	for(i=0;i<n1;i++)
	left[i]=a[l+i];
	for(j=0;j<n2;j++)
	right[j]=a[m+1+j];
	i=0,j=0,k=l;
	while(i<n1&&j<n2)
	{
		if(left[i]<right[j])
		{
			a[k++]=left[i++];
		}
		else a[k++]=right[j++];
	}
	while(i<n1)
	{
		a[k++]=left[i++];
	}
	while(j<n2)
	{
		a[k++]=right[j++];
	}
}

void mergeSort(int a[],int l,int h)
{
	if(l<h)
	{
		int mid=l+(h-l)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
return 0;
}

