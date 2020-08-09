// wildcard maTCHING problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, m;
	cin>>n>>m;
	int a[n+1][m+1];
	char p[n+1], s[m+1];
	cin>>p>>s;
	for (int i = 0; i < m+1; ++i)
		a[0][i] = 0;
	a[0][0] = 1;
	for (int i = 1; i < n+1; ++i)
		a[i][0] = ((p[i-1]=='*') ? a[i-1][0] : 0);
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < m+1; ++j){
			if(p[i-1]=='?' || s[j-1]==p[i-1])
				a[i][j] = a[i-1][j-1];
			else if(p[i-1]=='*')
				a[i][j] = a[i-1][j] || a[i][j-1];
			else
				a[i][j] = 0;
		}			
	cout<<a[n][m]<<endl;
    return 0;
}