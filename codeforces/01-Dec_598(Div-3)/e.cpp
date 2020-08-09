#include <bits/stdc++.h>
const int M = int(1e9) + 43;
using namespace std;
int main()
{
	int n,diff;
	cin>>n;
	int c[n+1],d[n+1];
	vector <pair<int,int> > v; 
	for (int i = 0; i < n; ++i)
	{
		cin>>diff;
		v.push_back(make_pair(diff, i)); 
	}
	sort(v.begin(), v.end()); 
	for (int i = 0; i < n+1; ++i)
	{
		d[i]=-1;
		c[i]=M;
	}
	c[0]=0;
	d[0]=0;
	for (int i = 0; i < n; ++i)
	{
		for (int l = 3; l <= 5 and i+l<=n; ++l)
		{
			diff = v[i+l-1].first - v[i].first;
			if(c[i+l]>diff+c[i])
			{
				c[i+l]=diff+c[i];
				d[i+l]=i;
			}
		}
	}
	int w=1,j=n;
	while(j>5)
	{
		for (int i = j; i > d[j]; --i)
			v[v[i-1].second].first=w;
		w++;
		j=d[j];
	}	
	for (int i = j-1; i >= 0; --i)
		v[v[i].second].first=w;
	cout<<c[n]<<" "<<w<<"\n";
    for (int i = 0; i < n; ++i)
	{
		cout<<v[i].first<<" ";
	}
    cout<<"\n";
	return 0;
}