// 0/1 knapsack problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, mw;
	cin>>n>>mw;
	int v[n+1];
	int w[n+1];
	int ww[n+1][mw+1];
	for (int i = 1; i < n+1; ++i)
		cin>>v[i];
	for (int i = 1; i < n+1; ++i){
		cin>>w[i];
		ww[i][0] = 0;
	}
	for (int i = 0; i < mw+1; ++i)
		ww[0][i] = 0;
	for (int i = 1; i < n+1; ++i){
		for (int j = 1; j < mw+1; ++j){
			if(j-w[i]>=0)
				ww[i][j] = max(v[i] + ww[i-1][j-w[i]], ww[i-1][j]);
			else
				ww[i][j] = ww[i-1][j];
		}
	}
	cout<<ww[n][mw]<<endl;
    return 0;
}