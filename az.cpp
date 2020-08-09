// # include <bits/stdc++.h>
# include "bit/std.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, s=0;
		cin>>n;
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		sort(a, a+n); 
		for (int i = 0; i < n; ++i)
			cin>>b[i];
		sort(b, b+n);
		for (int i = 0; i < n; ++i){
			s = s + min(a[i],b[i]);
		}
		cout<<s<<"\n";
	}
    return 0;
}