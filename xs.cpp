// # include <bits/stdc++.h>
# include "bit/std.h"
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t--){
		long long int n, p, e=0, s;
		cin>>n>>p;
		long long int d[n], r[n];
		for (long long int i = 0; i < n; ++i)
			r[i]=0;
		for (long long int i = 0; i < n; ++i){
			cin>>d[i];
			if (p%d[i]){
				e = 1;
				r[i] = abs(p/d[i]) + 1;
				break;
			}
		}
		if(e){
			cout<<"YES ";
			for (long long int i = 0; i < n; ++i)
				cout<<r[i]<<" ";
			cout<<"\n";
		} else{
			for (long long int i = 0; i < n-1; ++i){
				for (long long int j = i+1; j < n; ++j){
					if(d[j]%d[i]){
						r[j] = 1;
						r[i] = abs((p-d[j])/d[i]) + 1;
						e = 1;
						cout<<"YES ";
						for (long long int i = 0; i < n; ++i)
							cout<<r[i]<<" ";
						cout<<"\n";
						break;
					}
				}
				if(e) break;
			}
		}
		if(!e) cout<<"NO\n";
	}
    return 0;
}