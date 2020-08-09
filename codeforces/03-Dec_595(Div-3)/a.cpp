# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		sort(a,a+n);
		int f=0;
		for (int i = 0; i < n-1; ++i)
		{
			if(a[i]+1==a[i+1])
				f=1;
		}
		if(f==1)
			cout<<2<<"\n";
		else
			cout<<1<<"\n";
	}
    return 0;
}