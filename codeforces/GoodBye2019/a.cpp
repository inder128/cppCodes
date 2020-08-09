# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k1,k2,tmp;
		cin>>n>>k1>>k2;
		int m=0 ,p=0;
		for (int i = 0; i < k1; ++i)
		{
			cin>>tmp;
			if(tmp>m)
			{
				m=tmp;
				p=1;
			}
		}
		for (int i = 0; i < k2; ++i)
		{
			cin>>tmp;
			if(tmp>m)
			{
				m=tmp;
				p=2;
			}
		}
		if(p==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";

		
	}
    return 0;
}