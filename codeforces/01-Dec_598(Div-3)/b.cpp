#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1],swp[n];
		for (int i = 0; i < n; ++i)
			swp[i]=0;
		for (int i = 1; i < n+1; ++i)
			cin>>a[i];

		for (int i = 1; i <= n; ++i)
		{
			j=1;
			while(j<=n)
			{
				if(a[j]==i)
					break;
				j++;
			}
			if(j==i or swp[j-1]==1)
				swp[j]=1;

			for (int k = j-1; k > 0; --k)
			{
				if(swp[k]==0)
				{
					swap(a[k],a[k+1]);
					swp[k]=1;
				}
			}
		}

		for (int i = 1; i < n+1; ++i)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
    return 0;
}

