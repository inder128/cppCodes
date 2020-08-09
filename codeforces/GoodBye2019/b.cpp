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
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		int f=0 ,j=0;
		for (int i = 0; i < n-1; ++i)
		{
			if(abs(a[i+1]-a[i])>=2)
			{
				f=1;
				j=i;
				break;
			}
		}

		if(f)
			cout<<"YES\n"<<j+1<<" "<<j+2<<"\n";
		else
			cout<<"NO\n";
	}
    return 0;
}