#include <iostream> 
using namespace std; 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m, sa=0, sb=0, ib=0;
		cin>>n>>m;
		int a[n], b[m+1], ea=n-1;
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		for (int i = 0; i < m; ++i)
			cin>>b[i];
		b[m] = 1000000;
		while(sa<ea){
			while(b[ib]<=a[sa]) ib++;
			while(sb!=ib){
				swap(a[ea],b[sb]);
				ea--; sb++;
			}
			sa++;
		}
		sort(a, a+n); sort(b, b+m);
		for (int i = 0; i < n; ++i)
			cout<<a[i]<<" ";
		for (int i = 0; i < m; ++i)
			cout<<b[i]<<" ";
		cout<<endl;
	}
    return 0;
}

