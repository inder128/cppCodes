# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	char ac[n];
	int a[n],b[n],c[n];

	for (int i = 0; i < n; ++i)
		cin>>ac[i];

	for (int i = 0; i < n; ++i)
	{
		a[i] = ac[i]-'0';
		b[i]=a[i];
	}

	for (int i = 0; i < n-k; ++i)
	{
		b[i+k]=b[i];
	}


	int f=0,ff=0,fi=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]>b[i])
			f=1;
		if(b[i]>a[i])
			break;
	}

	if(f==0)
	{
		cout<<n<<"\n";
		for (int i = 0; i < n; ++i)
			cout<<b[i];
		cout<<"\n";
		return 0;
	}

	for (int i = 0; i < n; ++i)
		c[i]=b[i];
		
	

	for (int i = k-1; i >= 0; --i)
	{
		int j=i;
		while(b[i]==9 and j<n)
		{
			c[j]=0;
			j=j+k;
		}
		if(b[i]!=9)
		{
			ff=1;
			fi=i;
			break;
		}
	}


	if(ff)
	{
		int j=fi;
		while(j<n)
		{
			c[j]++;
			j=j+k;
		}
		cout<<n<<"\n";
		for (int i = 0; i < n; ++i)
			cout<<c[i];
		cout<<"\n";
	}
	else
	{
		cout<<n+1<<"\n1";
		for (int i = 0; i < n; ++i)
			cout<<c[i];
		cout<<"\n";
	}
    return 0;
}