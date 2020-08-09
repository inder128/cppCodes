// subset sum problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, m;
	cin>>n>>m;
	char a[n+1], b[m+1];
	int mm[n+1][m+1];
	cin>>a>>b;
	for (int i = 1; i < n+1; ++i)
		mm[i][0] = 1;
	for (int i = 1; i < m+1; ++i)
		mm[0][i] = 1;
	mm[0][0] = 0;
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < m+1; ++j)
			mm[i][j] =min(mm[i-1][j-1]+(a[i-1]==b[j-1] ? 0 : 1), min(mm[i-1][j], mm[i][j-1])+1);
	cout<<mm[n][m]<<endl;
    return 0;
}