// Maximum Size Rectangle of All 1's problem

#include <iostream> 
#include <stack>

using namespace std; 

int main()
{
	int n, m, t, i, top, area, marea=0, mxarea=0, si, ei, h;
	stack <int> s;
	cin>>n>>m;
	int a[n][m], st, sl, eb, er;
	for (int i = 0; i < n; ++i){
		cin>>a[i][0];
		for (int j = 1; j < m; ++j){
			cin>>t;
			a[i][j] = ((t) ? a[i][j-1]+1 : 0);
		}
	}
	for (int j = 0; j < m; ++j){
		i=0;
		while(i<n or !s.empty()){
			if (i<n and (s.empty() or a[s.top()][j]<=a[i][j])){ 
				s.push(i++); 
				continue; 
			}
			while(!s.empty() and (i==n or a[s.top()][j]>a[i][j])){
				top = s.top(); s.pop();
				area = ((s.empty()) ? a[top][j]*i : a[top][j]*(i-s.top()-1));
				if(area>marea){
					marea=area;
					si = ((s.empty()) ? 0 : s.top()+1);
					ei = i-1;
					h = a[top][j];
				}
			}
		}
		if(marea>mxarea){
			mxarea = marea;
			st = si;
			eb = ei;
			er = j;
			sl = j-h+1;
		}
	}
	printf("area:%d, st:%d, sl:%d, eb:%d, er:%d\n",mxarea,st,sl,eb,er);
    return 0;
}