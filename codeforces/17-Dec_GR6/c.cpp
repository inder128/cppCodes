# include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m,u,v,d,k,at,b,j,mini,c=0;
	cin>>n>>m;

	long long int a[n+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
			a[i][j]=0;
	}

	int ch[n+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
			ch[i][j]=0;
	}

	vector<int> first[n+1];
	vector<int> second[n+1]; 
	vector<int> f[n+1]; 

	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>d;
		first[u].push_back(v); 
		f[u].push_back(v); 
		second[v].push_back(u); 
		a[u][v] = a[u][v] + d;
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 0; j < first[i].size(); ++j)
		{
			k = first[i][j];
			for (int t = 0; t < first[k].size(); ++t)
			{
				at = first[k][t];
				if(a[i][k] and a[k][at])
				{
					mini = min(a[i][k],a[k][at]);
					a[i][at] = a[i][at] + mini;
					a[i][k] = a[i][k]-mini;
					a[k][at] = a[k][at]-mini;
					if(a[i][at] == mini) 
					{
						first[i].push_back(at); 
						f[i].push_back(at); 
						second[at].push_back(i); 
					}
				}
			}
			for (int t = 0; t < second[i].size(); ++t)
			{
				b = second[i][t];
				if(a[i][k] and a[b][i])
				{
					mini = min(a[i][k],a[b][i]);
					a[b][k] = a[b][k] + mini;
					a[i][k] = a[i][k]-mini;
					a[b][i] = a[k][at]-mini;
					if(a[b][k] == mini) 
					{
						first[b].push_back(k);
						f[b].push_back(k);
						second[b].push_back(k);  
					}
				}

			}
		}
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int k = 0; k < f[i].size(); ++k)
		{
			j = f[i][k];
			if(a[i][j] and j!=i and ch[i][j]==0)
			{
				c++;
				ch[i][j]=1;
			}
		}
	}
	cout<<c<<"\n";
	for (int i = 1; i < n+1; ++i)
	{
		for (int k = 0; k < f[i].size(); ++k)
		{
			j = f[i][k];
			if(a[i][j] and j!=i and ch[i][j])
			{
				cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
				ch[i][j]=0;
			}
		}
	}
	/*
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if(a[i][j] and j!=i)
				c++;
		}
	}
	cout<<c<<"\n";
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if(a[i][j] and j!=i)
				cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
		}
	}*/
    return 0;
}