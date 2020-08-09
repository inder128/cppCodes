// Weighted Job Scheduling problem
#include <iostream> 
using namespace std; 


int main()
{
	int n, m, sx, sy, ex, ey, ts=0, meh, msf, ss, se, es, ee;
	cin>>n>>m;
	int a[n][m], t[n], s[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin>>a[i][j];
	for (int i = 0; i < n; ++i)
		s[i][0] = a[i][0];
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			s[i][j] = s[i][j-1] + a[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j <= i; ++j){
			for (int k = 0; k < n; k++)
				t[k] = s[k][i] - ((j==0) ? 0 : s[k][j-1]);
			meh = 0; msf = 0; ss=0; se=-1; es=0; ee=-1;
			for (int k = 0; k < n; ++k){
				((meh+t[k]<=0) ? (meh=0, es=k+1, ee=k)  : (meh=meh+t[k], ee++));
				((meh>msf) ? (msf=meh, ss=es, se=ee) : 0);
			}
			(msf>ts) ? (sx=ss, sy=j, ex=se, ey=i, ts=msf) : 0;
		}	
	cout<<ts<<endl;
    return 0;
}




// int main()
// {
// 	int n, m, sx, sy, ex, ey, ts=0, meh, msf, ss, se, es, ee;
// 	cin>>n>>m;
// 	int a[n][m], t[n], s[n][m];
// 	for (int i = 0; i < n; ++i)
// 		for (int j = 0; j < m; ++j)
// 			cin>>a[i][j];
// 	for (int i = 0; i < n; ++i)
// 		s[i][0] = a[i][0];
// 	for (int i = 0; i < n; ++i)
// 		for (int j = 1; j < m; ++j)
// 			s[i][j] = s[i][j-1] + a[i][j];
// 	cout<<endl;cout<<endl;
// 	for (int i = 0; i < n; ++i){
// 		for (int j = 0; j < m; ++j)
// 			cout<<s[i][j]<<" ";
// 		cout<<endl;
// 	}cout<<endl;cout<<endl;
// 	for (int i = 0; i < m; ++i)
// 		for (int j = 0; j <= i; ++j){
// 			cout<<"i: "<<i<<" j: "<<j<<endl;
// 			for (int k = 0; k < n; k++)
// 				t[k] = s[k][i] - ((j==0) ? 0 : s[k][j-1]);
// 			for (int k = 0; k < n; ++k)
// 				cout<<t[k]<<" ";
// 			cout<<endl;
// 			meh = 0; msf = 0; ss=0; se=-1; es=0; ee=-1;
// 			for (int k = 0; k < n; ++k){
// 				((meh+t[k]<=0) ? (meh=0, es=k+1, ee=k)  : (meh=meh+t[k], ee++));
// 				((meh>msf) ? (msf=meh, ss=es, se=ee) : 0);
// 				cout<<"meh: "<<meh<<" msf: "<<msf<<"k: "<<k<<" es: "<<es<<" ee: "<<ee<<" ss: "<<ss<<" se: "<<se<<endl;
// 			}
// 			cout<<"sy: "<<sy<<" ey: "<<ey<<" sx: "<<sx<<" ex: "<<ex<<" t: "<<ts<<endl;
// 			cout<<"meh: "<<meh<<" msf: "<<msf<<" ss: "<<ss<<" se: "<<se<<endl;
// 			(msf>ts) ? sx=ss, sy=j, ex=se, ey=i, ts=msf : 0;
// 		}	
// 	cout<<"sy: "<<sy<<" ey: "<<ey<<" sx: "<<sx<<" ex: "<<ex<<" t: "<<ts<<endl;
//     return 0;
// }