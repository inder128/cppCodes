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
		int a[n],b[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		int j,c;
		for (int i = 0; i < n; ++i)
		{
			j=i;
			c=1;
			while(a[j]!=i+1)
			{
				j=a[j]-1;
				c++;
			}
			b[i]=c;
		}
		for (int i = 0; i < n; ++i)
			cout<<b[i]<<" ";
		cout<<"\n";
	}
    return 0;
}