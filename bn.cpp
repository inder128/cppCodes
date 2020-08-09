// rod cutting problem
#include <iostream> 
using namespace std; 

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		string c;
		cin>>c;
		n = c.length();
		int m[n][n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				m[i][j]=0;
		for (int i = 0; i < n; ++i)
			m[i][i] = 0;
		for (int i = 1; i < n; ++i)
			m[i-1][i] = (c[i-1]==c[i]) ? 0 : 1;
		for (int i = 2; i < n; ++i)
			for (int j = 0; j < n-i; ++j)
				m[j][j+i] = min(((c[j]==c[j+i]) ? 0 : 2) + m[j+1][j+i-1], 1 + min(m[j+1][j+i], m[j][j+i-1]));
		// for (int i = 0; i < n; ++i){
		// 	for (int j = 0; j < n; ++j)
		// 		cout<<m[i][j]<<" ";
		// 	cout<<"\n";
		// }
		cout<<m[0][n-1]<<endl;
	}
    return 0;
}