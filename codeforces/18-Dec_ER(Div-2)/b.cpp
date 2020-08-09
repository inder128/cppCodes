# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,d;
		cin>>a>>b;
		d = abs(a-b);
		if(min(a,b)>=d and (min(a,b)-d)%3==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}