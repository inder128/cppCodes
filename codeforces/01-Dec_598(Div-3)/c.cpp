#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,d;
	cin>>n>>m>>d;
	float c[m];
	float sc;
	for (int i = 0; i < m; ++i)
	{
		cin>>c[i];
		sc=sc+c[i];
	}
	int isc = sc;
	if((n-sc)/(m+1)>d-1)
	{
		cout<<"NO\n";
		return 0;
	}
	int a[m+1];
	for (int i = 0; i < m+1; ++i)
		a[i]=(n-isc)/(m+1);
	for (int i = 0; i < (n-isc)%(m+1); ++i)
		a[i]=a[i]+1;
	cout<<"YES\n";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < a[i]; ++j)
			cout<<0<<" ";
		for (int j = 0; j < c[i]; ++j)
			cout<<i+1<<" ";
	}
	for (int j = 0; j < a[m]; ++j)
			cout<<0<<" ";
	cout<<"\n";	
	return 0;
}