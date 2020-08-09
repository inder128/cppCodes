# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<n/2+2<<"\n";
		for (int i = 0; i <= n/2; ++i)
			cout<<i<<" ";
		cout<<n<<"\n";
	}
    return 0;
}