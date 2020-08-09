#include <iostream> 
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k, s, e; 
		cin>>n>>k;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		for (int i = 0; i < n; i+=k){
			s = i;
			e = (s+k>=n) ? n-1 : s+k-1;
			while(e>s) swap(a[s++], a[e--]);
		}
		for (int i = 0; i < n; ++i)
			cout<<a[i]<<" ";
		cout<<endl;
	}
    return 0;
}



