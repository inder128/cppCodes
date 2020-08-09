# include <bits/stdc++.h>
using namespace std;

int S,n,k;

int bs(int f ,int l, int a[])
{
	k = f + (l-f)/2;
	int b[n+1];
	for (int i = 1; i < n+1; ++i)
		b[i]=a[i]+i*k;
	sort(b+1,b+n+1);
	if(f==l)
		return b[k];
	if(b[k]>S)
		return bs(f,k-1,a);
	else
		return bs(k,l,a);
}



int main()
{
	cin>>n>>S;
	int a[n+1];	
	for (int i = 1; i < n+1; ++i)
		cin>>a[i];
	cout<<k<<" "<<bs(1,n,a)<<"\n";
    return 0;
}