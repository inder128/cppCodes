# include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int mf = min(b,c);
	int s = 0;
	if(e>=f)
	{
		if(d>=a)
		{
			s = s + a*e;
			d = d-a;
			s = s + min(mf,d)*f; 
		}
		else
		{
			s = s + d*e;
		}
	}
	else
	{
		if(d>=mf)
		{
			s = s + mf*f;
			d = d-mf;
			s = s + min(a,d)*e; 
		}
		else
		{
			s = s + d*f;
		}
	}
	cout<<s<<"\n";
    return 0;
}