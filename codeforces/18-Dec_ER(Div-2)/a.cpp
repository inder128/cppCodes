# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,c,sum,a,r;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>c>>sum;
		a = sum/c ;
		r = sum%c ;
		cout<<r*(a+1)*(a+1)+(c-r)*a*a<<"\n";
	}
    return 0;
}