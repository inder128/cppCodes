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
		int mini = min(min(r,g),b);
		int maxi = max(max(r,g),b);
		int med = r+g+b-mini-maxi;

		int d=maxi-med;
		if(d>=mini)
			med=med+mini;
		else
		{
			med=med+d;
			mini=mini-d;
			maxi=maxi+mini/2;
			med=med+mini-mini/2;
		}
		cout<<min(maxi,med)<<"\n";
	}
    return 0;
}