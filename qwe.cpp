// matrix chain multipication problem

#include <iostream> 

using namespace std; 

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	int m[n+1][n+1];
	for (int i = 0; i < n+1; ++i)
		cin>>a[i];
	for (int j = 0; j < n-1; ++j)
		m[j][j+2] = a[j]*a[j+1]*a[j+2];
	for (int i = 3; i < n+1; ++i)
		for (int j = 0; j < n-i+1; ++j)
			m[j][j+i] = min(m[j][j+i-1]+a[j]*a[j+i-1]*a[j+i], m[j+1][j+i]+a[j]*a[j+1]*a[j+i]);
	cout<<m[0][n]<<endl;
    return 0;
}