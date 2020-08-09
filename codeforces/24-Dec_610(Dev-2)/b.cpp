# include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,k;
		cin>>n>>p>>k;
		int a[n+1];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		sort(a,a+n);
		int s1=0,pt=0,m=0,i,b=1;
		for (i = 1; i < n; i=i+2)
		{
			if(pt+a[i]<=p)
				pt = pt+a[i];
			else
			{
				if(pt+a[i-1]<=p)
					s1=s1+1;
				b=0;
				break;
			}
			s1=s1+2;
		}
		if(b and pt+a[n-1]<=p and n%2)
			s1=s1+1;
 
		int s2=0;
		pt=0,b=1;
		for (i = 2; i < n; i=i+2)
		{
			if(pt+a[i]<=p)
				pt = pt+a[i];
			else
			{
				if(pt+a[0]<=p)
				{
					s2=s2+1;
					pt = pt+a[0];
				}
				if(pt+a[i-1]<=p)
					s2=s2+1;
				b=0;
				break;
			}
			s2=s2+2;
		}
		if(b and pt+a[0]<=p)
		{
			s2=s2+1;
			pt = pt+a[0];
		}
		if(b and pt+a[n-1]<=p and n%2==0)
			s2=s2+1;
		
		
		cout<<max(s1,s2)<<"\n";
	}
    return 0;
}