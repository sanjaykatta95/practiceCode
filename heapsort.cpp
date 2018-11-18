#include <bits/stdc++.h>
using namespace std;
#define long long int ll

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void minHeapify(int a[],int n,int i)
{
	int heapsize = n;
	int l = 2*i+1;
	int r = 2*i+2;
	int smallest = i;
	if(l<heapsize&&a[l]<a[smallest])
	smallest = l;
	if(r<heapsize&&a[r]<a[smallest])
	smallest = r;
	if(smallest!=i)
	{
		swap(&a[i],&a[smallest]);
		minHeapify(a,n,smallest);
	}
}

	void heapsort(int a[],int n)
	{
		int i = (n-1)/2;
		for(i=n/2-1;i>=0;i--)
		minHeapify(a,n,i);
		for(i=n-1;i>=0;i--)
		{
			swap(&a[i],&a[0]);
			minHeapify(a,i,0);
		}
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}

int main()
{
int a[] = {5,3,2,9,10};
int n=sizeof(a)/sizeof(a[0]);
heapsort(a,n);
return 0;
}

