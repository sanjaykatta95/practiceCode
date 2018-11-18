#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int main()
{
	ios_base::sync_with_stdio(false);
	int n,i=0,temp=0;
	cin>>n;
	char hex[10];
	while(n!=0)
	{
		temp=0;
		temp=n%16;
		if(temp<10)
		hex[i++]=temp+48;
		else hex[i++]=temp+55;
		n=n/16;
	}
	for(int j=i-1;j>=0;j--)
	cout<<hex[j];
	cout<<endl;
return 0;
}

