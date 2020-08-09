# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	char c[n];
	int a[26];
	char t;
	for (int i = 0; i < 26; ++i)
		a[i]=0;
	for (int i = 0; i < n; ++i)
		cin>>c[i];
	for (int i = 0; i < k; ++i)
	{
		cin>>t;
		a[t-'a']=1;
	}
	long long int s=0 , total=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[c[i]-'a'])
			s++;
		else
		{
			total = total + (s*(s+1))/2;
			s=0;
		}
	}
	cout<<total + (s*(s+1))/2<<"\n";
    return 0;
}