# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,c;
	cin>>n>>c;
	int x[n+1],y[n+1],a[n],b[n];
	for (int i = 1; i < n; ++i)
		cin>>a[i];
	for (int i = 1; i < n; ++i)
		cin>>b[i];
	x[0]=0; x[1]=0; x[2]=a[1];
	y[0]=0; y[1]=0; y[2]=c+b[1];
	for (int i = 3; i <= n; ++i)
	{
		y[i]=min(x[i-1]+c+b[i-1],y[i-1]+b[i-1]);
		x[i]=min(x[i-1],y[i-1])+a[i-1];
	}
	for (int i = 1; i <= n; ++i)
		cout<<min(x[i],y[i])<<" ";
	cout<<"\n";
	return 0;
}