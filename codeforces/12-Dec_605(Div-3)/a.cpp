# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int l=0,r=0,u=0,d=0;
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i]=='L')
				l++;
			else if(s[i]=='R')
				r++;
			else if(s[i]=='U')
				u++;
			else
				d++;
		}
		if(min(u,d)==0 and min(l,r)==0)
			cout<<"0\n";
		else if(min(u,d)==0 and min(l,r)>0)
			cout<<"2\nLR\n";
		else if(min(u,d)>0 and min(l,r)==0)
			cout<<"2\nUD\n";
		else
		{
			cout<<2*min(l,r)+2*min(u,d)<<"\n";
			for (int i = 0; i < min(l,r); ++i)
				cout<<"L";
			for (int i = 0; i < min(u,d); ++i)
				cout<<"U";
			for (int i = 0; i < min(l,r); ++i)
				cout<<"R";
			for (int i = 0; i < min(u,d); ++i)
				cout<<"D";
			cout<<"\n";
		}
	}
    return 0;
}