#include <bits/stdc++.h>
#include <queue> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		queue <int> q;
		long long int n,k;
		cin>>n>>k;
		long long int b[n];
		char ch;
		for (long long int i = 0; i < n; ++i)
		{
			cin>>ch;
			b[i] = ch - '0';
			if(b[i]==0)
				q.push(i);
		}
		long long int c=0,j=0,l=0;
		while(true)
		{
			if(c==k or j>n-2 or q.empty())
				break;
			l=q.front();
			q.pop();
			if(k-c>=l-j)
			{
				c=c+l-j;
				b[l]=1;
				b[j]=0;
			}
			else
			{
				b[l]=1;
				b[l-(k-c)]=0;
				c=k;
			}
			j++;
		}
		for (long long int i = 0; i < n; ++i)
			cout<<b[i];
		cout<<"\n";
	}
	return 0;
}