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
		int sum = 0 , f2 = 0 , f0 = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			sum = sum + (s[i]-'0');
			if(s[i]=='0')
				f0++;
			if((s[i]-'0')%2 == 0  and s[i]!='0')
				f2 = 1;
		}
		if(sum%3==0 and f0 and (f2 or f0>1))
			cout<<"red\n";
		else
			cout<<"cyan\n";
	}
    return 0;
}