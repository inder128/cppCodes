// matrix chain multipication problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, m, mx=0, mi=-1, mj=-1;
	cin>>n>>m;
	char a[n+1], b[m+1];
	cin>>a>>b;
	int mm[n][m];
	mm[0][0] = ((a[0]==b[0]) ? 1 : 0);
	for (int i = 1; i < m; ++i)
		mm[0][i] = mm[0][i-1] || (a[0]==b[i]);
	for (int i = 1; i < n; ++i)
		mm[i][0] = mm[i-1][0] || (b[0]==a[i]);
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			mm[i][j] = ((a[i]==b[j]) ? mm[i-1][j-1]+1 : 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			(mm[i][j]>mx) ? (mx=mm[i][j], mi=i, mj=j) : 0;
	cout<<"max-len: "<<mx<<",  arr1-end: "<<mi<<",  arr2-end: "<<mj<<endl;
    return 0;
}