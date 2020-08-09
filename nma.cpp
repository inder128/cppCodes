// rod cutting problem

#include <iostream> 

using namespace std; 

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, x=-1, y=-1;
		string c;
		cin>>c;
		n = c.length();
		int m[n][n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				m[i][j]=0;
		for (int i = 0; i < n; ++i)
			m[i][i] = 1;
		for (int i = 1; i < n; ++i)
			m[i-1][i] = (c[i-1]==c[i]) ? 1 : 0;
		for (int i = 2; i < n; ++i)
			for (int j = 0; j < n-i; ++j){
				m[j][j+i] = ((c[j]==c[j+i]) ? m[j+1][j+i-1] : 0);
			}
		for (int i = n-1; i >= 0; --i){
			if(x>=0) break;
			for (int j = 0; j < n-i; ++j)
				if(m[j][j+i]){
					x = j;
					y = j+i;
					break;	
				} 
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<m[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		for (int k = x; k <= y; ++k)
			cout<<c[k];
		cout<<endl;
	}
    return 0;
}