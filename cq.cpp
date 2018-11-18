#include <bits/stdc++.h>
using namespace std;
#define long long int ll

class circularQueue
{
	int front,rear,size,*a;
	public:
		circularQueue(int size)
		{
			a=new int[size];
			front=-1;
			rear=-1;
			this->size=size;
		}
		bool isEmpty()
		{
			if(front==-1)
			return true;
		}
		bool isFull()
		{
			if(front==(rear+1)%size)
			return true;
			return false;
		}
		void enq(int data)
		{
			if(isFull())
			{
				cout<<"queue is full"<<endl;
			}
			if(front==-1)
			front=0;
			rear = (rear+1)%size;
			a[rear]=data;
		}
		int deq()
		{
			if(isEmpty())
			{
				cout<<"queue is empty"<<endl;
				return -1;
			}
			int item=a[front];
			if(front==rear)
			{
				front=rear=-1;
			}
			else
			front=(front+1)%size;
			return item;
		}
		void display()
		{
			for(int i=front;i!=rear;i=(i+1)%size)
			cout<<a[i]<<" ";
		}
		int Size()
		{
			if(rear>front)
			return rear-front+1;
			else return (size-(front-rear+1));
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	circularQueue cq(3);
    cq.enq(10);
    cq.enq(100);
    cq.enq(1000);
    
    cout << endl << "Size of queue: " << cq.Size();
    
    cout << endl << "Removed element: " << cq.deq();
    
    cq.display();
    return 0;
}

