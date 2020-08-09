// subset sum problem

#include <iostream> 

using namespace std; 

int main()
{
	int n;
	cin>>n;
	int a[n], s;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	cin>>s;
	int m[n+1][s+1];
	for (int i = 0; i < n+1; ++i)
		m[i][0] = 1;
	for (int i = 1; i < s+1; ++i)
		m[0][i] = 0;
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < s+1; ++j)
			m[i][j] = m[i-1][j] || ((j-a[i-1] >= 0) ? m[i-1][j-a[i-1]] : 0);
	cout<<(m[n][s] ? "YES" : "NO")<<endl;
    return 0;
}