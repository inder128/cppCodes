# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int at,bt,a,b,c,r,m,M;
		cin>>at>>bt>>c>>r;
		a = min(at,bt);
		b = max(at,bt);
		if(c<=b and c>=a)
		{
			M = max(a,c-r);
			m = min(b,c+r);
			cout<<((b-a)-(m-M))<<"\n";
		}
		else if(c<a)
		{
			m = max(a,c+r);
			if(((b-a)-(m-a))>0)
				cout<<((b-a)-(m-a))<<"\n";
			else
				cout<<0<<"\n";
		}
		else
		{
			M = min(b,c-r);
			if(((b-a)-(b-M))>0)
				cout<<((b-a)-(b-M))<<"\n";
			else
				cout<<0<<"\n";
		}
		
	}
    return 0;
}