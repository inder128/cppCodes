# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n] , l[n] , f[n];

	for (int i = 0; i < n; ++i)
		cin>>a[i];

	f[0]=1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]>a[i-1])
			f[i]=f[i-1]+1;
		else
			f[i]=1;
	}

	l[n-1]=1;
	for (int i = n-2; i >= 0; --i)
	{
		if(a[i+1]>a[i])
			l[i]=l[i+1]+1;
		else
			l[i]=1;
	}

	int maxm = 0;
	for (int i = 0; i < n; ++i)
	{
		if(maxm<l[i])
			maxm=l[i];
	}

	for (int i = 1; i < n-1; ++i)
	{
		if(maxm < l[i+1] + f[i-1]  and a[i+1]>a[i-1])
			maxm = l[i+1] + f[i-1];
	}



	cout<<maxm<<"\n";
    return 0;
}