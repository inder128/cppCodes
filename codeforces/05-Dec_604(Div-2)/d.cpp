# include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==0 and b==0 and d==c+1)
	{
		cout<<"YES\n";
		for (int i = 0; i < min(d,c); ++i)
			cout<<3<<" "<<2<<" ";
		cout<<3<<"\n";
		return 0;
	}
	if(c==0 and d==0 and a==b+1)
	{
		cout<<"YES\n";
		for (int i = 0; i < min(a,b); ++i)
			cout<<0<<" "<<1<<" ";
		cout<<0<<"\n";
		return 0;
	}
	if(!(b>=a and c>=d and max(b-a,c-d)-min(b-a,c-d)<=1))
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(b-a>c-d)
		cout<<1<<" ";
	for (int i = 0; i < a; ++i)
		cout<<0<<" "<<1<<" ";
	for (int i = 0; i < min(b-a,c-d); ++i)
		cout<<2<<" "<<1<<" ";
	for (int i = 0; i < d; ++i)
		cout<<2<<" "<<3<<" ";
	if(b-a<c-d)
		cout<<2<<" ";
	cout<<"\n";
    return 0;
}