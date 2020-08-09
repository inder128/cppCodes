# include <iostream>
using namespace std;

int fon(int a[], int n, int s){
	int i=0, j=n-1, ts, t=0;
	while(i<j){
		ts = a[i] + a[j];
		if(ts<s) i++;
		else if(ts>s) j--;
		else{ t++; i++; }
	}
	return t;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, t=0;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		sort(a, a+n);
		for (int i = n-1; i >= 2; --i)
			t += fon(a, i, a[i]); 
		cout<<((t) ? t : -1)<<endl;
	}
    return 0;
}