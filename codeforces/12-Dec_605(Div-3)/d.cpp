# include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int a[n] , x[n];
	for (long long int i = 0; i < n; ++i)
		cin>>a[i];
	vector <long long int> v;
	v.push_back(-1);
	for (long long int i = 0; i < n-1; ++i)
	{
		if(a[i+1]<=a[i])
			v.push_back(i);
	}
	v.push_back(n-1);

	

	

	
	for (long long int i = 0; i < v.size()-1; ++i)
	{
		for (long long int j = v[i]+1; j <= v[i+1]; ++j)
			x[j] = v[i+1]-v[i];
	}

	
	long long int s=0;
	for (long long int i = 1; i < v.size()-1; ++i)
	{
		if(x[v[i]]==1 and s < x[v[i]-1] + x[v[i]+1] and v[i] and  a[v[i]-1]<a[v[i]+1])
		{
			s = x[v[i]-1] + x[v[i]+1];
		}
		else if(s < x[v[i]] + x[v[i]+1] -1  and  a[v[i]-1]<a[v[i]+1])
		{
			s = x[v[i]] + x[v[i]+1] -1 ;
		}
	}


	for (long long int i = 0; i < n; ++i)
	{
		if(s<x[i])
		{
			s=x[i];
		}
	}

	




	cout<<s<<"\n";

    return 0;
}