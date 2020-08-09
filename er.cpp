#include <iostream> 
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m; 
		int a1=0, a2=0, a3=0; 
		int b1=0, b2=0, b3=0, b4=0;
		long long int t=0;
		cin>>n>>m;
		int a[n], b[m], sa=0, sb=0;
		for (int i = 0; i < n; ++i){
			cin>>a[i];
			if(a[i]==1) a1++;
			if(a[i]==2) a2++;
			if(a[i]==3) a3++;
		}
		for (int i = 0; i < m; ++i){
			cin>>b[i];
			if(b[i]==1) b1++;
			if(b[i]==2) b2++;
			if(b[i]==3) b3++;
			if(b[i]==4) b4++;
		}
		sort(a, a+n);  sort(b, b+m);
		while(sa<n){
			while(sb<m and b[sb]<=a[sa]) 
				sb++;
			t += m-sb;
			sa++;
		}
		cout<<t - a2*b3 - a2*+b4 + a3*b2 + (b1*n - a1*m)<<endl;
	}
    return 0;
}



