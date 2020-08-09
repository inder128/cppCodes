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
		int a[n],b[n],f[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			f[i]=0;
		}
		int j,c;
		for (int i = 0; i < n; ++i)
		{
			j=i;
			c=1;
			if(f[i]==0)
			{
				while(a[j]!=i+1)
				{
					j=a[j]-1;
					c++;
				}
				j=i;
				b[j]=c;
				while(a[j]!=i+1)
				{
					f[j]=1;
					b[j]=c;
					j=a[j]-1;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			cout<<b[i]<<" ";
		cout<<"\n";
	}
    return 0;
}