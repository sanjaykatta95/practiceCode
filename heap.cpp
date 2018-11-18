#include <bits/stdc++.h>
using namespace std;
#define long long int ll

class MinHeap
{
	int capacity,heapsize,*harr;
	public:
		MinHeap(int capacity)
		{
			harr = new int[capacity];
			heapsize=0;
			this->capacity=capacity;
		}
		int left(int i)
		{
			return (2*i+1);
		}
		int right(int i)
		{
			return (2*i+2);
		}
		int parent(int i)
		{
			return (i-1)/2;
		}
		void insertKey(int key)
		{
			int i;
			if(heapsize==capacity)
			return;
			heapsize++;
			i=heapsize-1;
			harr[i]=key;
			while(i!=0&&harr[i]<harr[parent(i)])
			{
				swap(&harr[i],&harr[parent(i)]);
				i=parent(i);
			}
		}
		void decreaseKey(int i,int value)
		{
			harr[i]=value;
			while(i!=0&&harr[i]<harr[parent(i)])
			{
				swap(&harr[i],&harr[parent(i)]);
				i=parent(i);
			}
		}
		void minheapify(int i)
		{
			int smallest=i;
			int l=left(i);
			int r= right(i);
			if(l<heapsize&&harr[l]<harr[smallest])
			smallest=l;
			if(r<heapsize&&harr[r]<harr[smallest])
			smallest=r;
			if(smallest!=i)
			{
				swap(&harr[i],&harr[smallest]);
				minheapify(smallest);
			}
		}
		void swap(int *a,int *b)
		{
			int c=*a;
			*a=*b;
			*b=c;
		}
		int extractMin()
		{
			if(heapsize==0)
			return -1;
			if(heapsize==1)
			{
				heapsize=0;
				return harr[0];
			}
			int root = harr[0];
			harr[0]=harr[heapsize-1];
			heapsize--;
			minheapify(0);
			return 0;
		}
		int getMin()
		{
			return harr[0];
		}
		void deleteKey(int i)
		{
			decreaseKey(i,INT_MIN);
			extractMin();
		}
		void printarray()
		{
			for(int i=0;i<heapsize;i++)
			cout<<harr[i]<<" ";
			cout<<endl;
		}
		void heapsort()
		{
			int i,n=heapsize;
			for(i=n/2-1;i>=0;i--)
			minheapify(i);
			for(i=heapsize-1;i>=0;i--)
			{
				swap(&harr[0],&harr[i]);
				minheapify(0);
			}
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	 MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.printarray();
//    cout << h.extractMin() << " ";
//    cout << h.getMin() << " ";
//    h.decreaseKey(2);
//    cout << h.getMin();
return 0;
}

