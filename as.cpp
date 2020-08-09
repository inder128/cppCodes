// 2+1 string matching problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	char a[n+2], b[m+2], c[k+2];
	int mm[n+1][m+1];
	cin>>(a+1)>>(b+1)>>(c+1);
	mm[0][0] = 0;
	for (int i = 1; i < m+1; ++i)
		mm[0][i] = ((mm[0][i-1]==i-1 and b[i]==c[i]) ? i : -1);
	for (int i = 1; i < n+1; ++i)
		mm[i][0] = ((mm[i-1][0]==i-1 and a[i]==c[i]) ? i : -1);
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < m+1; ++j)
			if (c[i+j]==a[i] and mm[i-1][j]==i+j-1) mm[i][j] = i+j;
			else if (c[i+j]==b[j] and mm[i][j-1]==i-1+j) mm[i][j] = i+j;
			else mm[i][j] = -1;
	cout<<((mm[n][m]==n+m) ? "YES\n" : "NO\n");
    return 0;
}