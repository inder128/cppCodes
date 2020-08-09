# include <bits/stdc++.h>
using namespace std;


int v(int a,int b,int c,int d,int s1,int s2)
{
	int f=0;
	f = f + ((a+c)<=s1 and b<=s2 and d<=s2);
	f = f + ((a+d)<=s1 and b<=s2 and c<=s2);
	f = f + ((b+c)<=s1 and a<=s2 and d<=s2);
	f = f + ((b+d)<=s1 and a<=s2 and c<=s2);
	return f;
}


int main()
{
	int n,s1,s2;
	cin>>n>>s1>>s2;
	int x[n],y[n];
	for (int i = 0; i < n; ++i)
		cin>>x[i]>>y[i];
	int s=0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(v(x[i],y[i],x[j],y[j],s1,s2) or v(x[i],y[i],x[j],y[j],s2,s1))
			{
				if((x[i]*y[i]+x[j]*y[j])>s)
					s = x[i]*y[i]+x[j]*y[j];
			}
		}
	}
	cout<<s<<"\n";
    return 0;
}