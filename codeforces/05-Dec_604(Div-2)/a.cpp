# include <bits/stdc++.h>
#include <string> 
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int f=0;
		for (int i = 0; i < s.length()-1; ++i)
		{
			if(s[i]==s[i+1] and s[i]!='?')
				f=1;
		}
		if(s[0]=='?')
		{
			if(s[1]!='a')
				s[0]='a';
			else
				s[0]='b';
		}
		for (int i = 1; i < s.length()-1; ++i)
		{
			if(s[i]=='?')
			{
				if(s[i-1]!='a' and s[i+1]!='a')
					s[i]='a';
				else if(s[i-1]!='b' and s[i+1]!='b')
					s[i]='b';
				else
					s[i]='c';
			}
		}
		if(s[s.length()-1]=='?')
		{
			if(s[s.length()-2]!='a')
				s[s.length()-1]='a';
			else
				s[s.length()-1]='b';
		}
		if(f==1)
			cout<<-1<<"\n";
		else
			cout<<s<<"\n";
	}
    return 0;
}