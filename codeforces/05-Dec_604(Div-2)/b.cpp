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
		int a[n+1];
		int b[n+1];
		for (int i = 1; i < n+1; ++i)
		{
			cin>>a[i];
			b[a[i]]=i;
		}
		int maxi=b[1],mini=b[1];
		cout<<1;
		for (int i = 2; i < n+1; ++i)
		{
			maxi=max(maxi,b[i]);
			mini=min(mini,b[i]);
			if(maxi-mini<i)
				cout<<1;
			else
				cout<<0;
		}
		cout<<"\n";
	}
    return 0;
}