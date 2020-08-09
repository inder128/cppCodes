// egg droping problem

#include <iostream> 

using namespace std; 

int main()
{
	int e, f, mx;
	cin>>e>>f;
	int m[e+1][f+1];
	for (int i = 0; i < f+1; ++i)
		m[1][i] = i;
	for (int i = 2; i < e+1; ++i)
		m[i][0] = 0;
	for (int i = 2; i < e+1; ++i)
		for (int j = 1; j < f+1; ++j){
			mx = max(m[i-1][0], m[i][j-1]);
			for (int p = 1; p < j; ++p)
				mx = min(max(m[i-1][p], m[i][j-p-1]), mx);
			m[i][j] = mx+1;
		}
	cout<<m[e][f]<<endl;
    return 0;
}