# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		if(n%14<7 and n%14>0 and n>14)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}

