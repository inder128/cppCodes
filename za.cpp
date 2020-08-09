// # include <bits/stdc++.h>
# include "bit/std.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n], f[n+1], l[n+1];
		for (int i = 0; i < n; ++i)
			cin>>a[i];

		f[0]=0;
		for (int i = 1; i < n+1; ++i){
			f[i] = f[i-1] + a[i-1]%k;
		}

		l[n]=0;
		for (int i = n-1; i >= 0; --i){
			l[i] = l[i+1] + (a[i]%k>0 ? k-a[i]%k : 0);
		}
		
		int m = f[n];	
		for (int i = 0; i < n+1; ++i){
			if(f[i]-l[i]>=0 and f[i]-l[i]<m)
				m = f[i]-l[i];
		}
		cout<<m<<"\n";

		// for (int i = 0; i < n+1; ++i)
		// 	cout<<f[i]<<" ";
		// cout<<"\n";
		// for (int i = 0; i < n+1; ++i)
		// 	cout<<l[i]<<" ";
		// cout<<"\n";
	}
    return 0;
}