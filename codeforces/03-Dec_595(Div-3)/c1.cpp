# include <bits/stdc++.h>
using namespace std;

int ifind(long long int n , long long int S[])
{
	int i;
	for (i = 0; i < 39; ++i)
	{
		if(S[i]<=n and n<S[i+1])
			break;
	}
	return i;
}

long long int ans(long long int n , long long int S[])
{
	int i=ifind(n,S);
	if(S[i]==n)
		return n;
	if(pow(3,i+1)>=n)
		return pow(3,i+1);
	return pow(3,i+1)+ans(n-pow(3,i+1),S);
}


int main()
{
	long long int S[39];
	S[0]=1;
	for (int i = 1; i < 39; ++i)
    	S[i]=S[i-1]+pow(3,i);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		cout<<ans(n,S)<<"\n";
	}
    return 0;
}