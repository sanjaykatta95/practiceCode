#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int maxSubArraySum(int a[],int n)
{
	int cur_max=a[0],max_so_far=a[0],i;
	for(i=1;i<n;i++)
	{
		cur_max=max(cur_max+a[i],a[i]);
		max_so_far = max(max_so_far,cur_max);
	}
	return max_so_far;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
return 0;
}

