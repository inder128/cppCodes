# include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,p,k;
		cin>>n>>p>>k;
		long long int a[n+1];
		for (long long int i = 1; i <= n; ++i)
			cin>>a[i];
		a[0]=0;
		sort(a,a+n+1);
		long long int s,pt,m=0,j,b=0;
		for (long long int i = k; i < 2*k and i <= n ; ++i)
		{
			pt=0;
			s=0;
			for (long long int u = 1; u <= i-k; ++u)
			{
				if(pt+a[u]<=p)
					pt = pt+a[u];
				else
				{
					b=1;
					break;
				}
				s++;
			}
			if(b)
				break;
			for (j = i; j <= n ; j=j+k)
			{
				if(pt+a[j]<=p)
					pt = pt+a[j];
				else
					break;
				s = s+k;
			}
			for (long long int u = j-k+1 ; u < j and u <= n ; ++u)
			{
				if(pt+a[u]<=p)
					pt = pt+a[u];
				else
					break;
				s++;
			}
			if(s>m)
				m=s;
		}
		cout<<m<<"\n";
	}
    return 0;
}