# include <iostream>
using namespace std;
long long int INF = 1000000000000000000;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, s, x=0, y=0, ts;
		cin>>n>>s;
		long long int a[n+1];
		a[n] = INF;
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		ts = a[0];
		while(1 and x!=n)
			if(ts<s)
				ts += a[++y];
			else if(ts>s)
				ts -= a[x++];
			else
				break;
		if(x==n) cout<<-1<<endl;
		else cout<<x+1<<" "<<y+1<<endl;
	}
    return 0;
}