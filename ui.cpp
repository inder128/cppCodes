#include <iostream> 
#include <stack> 
using namespace std;

int rtf(int a[], int n, int e){
	int s = 1;
	while(s<e){
		if(a[s]==0) s++;
		else if(a[e]==0) e--;
		else if(s*s+e*e>n*n) e--;
		else if(s*s+e*e<n*n) s++;
		else return 1;
	}
	return 0;
}

int main(){
	int t, n, a[1001], tt;
	cin>>t;
	while(t--){
		for (int i = 0; i < 1001; ++i)
			a[i] = 0;
		cin>>n;
		for (int i = 0; i < n; ++i){
			cin>>tt;
			a[tt] = 1;
		}
		tt = 0;
		for (int i = 1000; i >= 3; --i)
			if(a[i]) tt += rtf(a, i, i-1);
		cout<<((tt) ? "YES" : "NO")<<endl;
	}
    return 0;
}