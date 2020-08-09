#include <bits/stdc++.h>
int M=1000000;
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n],c[n][n],d[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j]=0;
			d[i][j]=0;
		}
	}
	vector <pair<int,int> > v; 
	vector <int> ind;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		v.push_back(make_pair(a[i], i)); 
	}
	sort(a, a+n); 
	sort(v.begin(), v.end()); 
	for (int i = 0; i < n; ++i)
		c[i][i]=M;
	int sum,m;
	for (int i = 1; i < n; ++i)
	{
		m=i;
		for (int l = 0; m < n; ++l)
		{
			if(m-l>=2)
				sum=a[m]-a[l];
			else
				sum=M;
			d[l][m]=m;
			for (int j = m-1; j >= l; --j)
			{
				if(c[l][j]+c[j+1][m]<sum)
				{
					sum=c[l][j]+c[j+1][m];
					d[l][m]=j;
				}
			}
			c[l][m]=sum;
			m++;
		}
	}
	stack<pair<int,int> > s;
	pair <int, int> t; 
	int i;
	s.push(make_pair(0,n-1));
	while(!s.empty())
	{
		t=s.top();
		s.pop();
		i=d[t.first][t.second];
		if(t.second!=i)
		{
			ind.push_back(i);
			s.push(make_pair(t.first,i));
			s.push(make_pair(i,t.second));
		}
	}
	sort(ind.begin(), ind.end()); 
	m=0;
	int w=1;
	for (auto i = ind.begin(); i != ind.end(); ++i) 
	{
         for (int j = m; j <= *i ; ++j)
	         a[v[j].second]=w;
	     m=*i+1;
	     w++;
	}
	for (int i = m; i < n; ++i)
		a[v[i].second]=w;
	cout<<c[0][n-1]<<" "<<*max_element(a,a+n)<<"\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
    cout<<"\n";
	return 0;
}

