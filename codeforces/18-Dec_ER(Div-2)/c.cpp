# include <bits/stdc++.h>
# include <algorithm> 
using namespace std;

int main()
{
	int t,r,b,k,M,m,f;
	cin>>t;
	while(t--)
	{
		cin>>r>>b>>k;
		M = max(r,b) - __gcd(r,b);
		m = min(r,b);
		if(M%m==0)
			f=1;
		else
			f=0;
		if((M/m-f+1)>=k)
			cout<<"REBEL\n";
		else
			cout<<"OBEY\n";

	}
    return 0;
}