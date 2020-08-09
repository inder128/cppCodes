// # include <bits/stdc++.h>
# include "bit/std.h"
using namespace std;

int main()
{
	int t, S=0;
	cin>>t;
	while(t--){
		int n, s=-400, t, tmps, tmpa[4];
		char l, a='A';
		int m[4][4];
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j)
				m[i][j]=0;
		}
		cin>>n;
		for (int i = 0; i < n; ++i){
			cin>>l>>t;
			m[l-a][t/3-1]++;
		}
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j){
				for (int k = 0; k < 4; ++k){
					for (int l = 0; l < 4; ++l){
						if(i!=j and i!=k and i!=l and j!=k and j!=l and k!=l){
							tmpa[0] = m['A'-a][i];
							tmpa[1] = m['B'-a][j];
							tmpa[2] = m['C'-a][k];
							tmpa[3] = m['D'-a][l];
							sort(tmpa, tmpa+4);
							tmps = 0;
							tmps = tmps + (tmpa[3]>0 ? tmpa[3]*100 : -100);
							tmps = tmps + (tmpa[2]>0 ? tmpa[2]*75 : -100);
							tmps = tmps + (tmpa[1]>0 ? tmpa[1]*50 : -100);
							tmps = tmps + (tmpa[0]>0 ? tmpa[0]*25 : -100);
							if(tmps>s)
								s = tmps;
						}
					}
				}
			}
		}
		cout<<s<<"\n";
		S = S + s;
	}
	cout<<S<<"\n";
    return 0;
}