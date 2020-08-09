// baloon problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, tm;
	cin>>n;
	int a[n+2], m[n+2][n+2];
	a[0] = 1; a[n+1] = 1;
	for (int i = 1; i < n+1; ++i)
		cin>>a[i];
	for (int i = 0; i < n+1; ++i)
		m[i+1][i] = 0;
	for (int i = 1; i < n+1; ++i){
		for (int j = 0; j < n+1-i; ++j){
			m[j+1][i+j] = 0;
			for (int k = j+1; k < i+j+1; ++k){
				tm = m[j+1][k-1] + a[j+1-1]*a[k]*a[i+j+1] +m[k+1][i+j];
				if(tm > m[j+1][i+j]) m[j+1][i+j] = tm;
			}
		}
	}
	cout<<m[1][n]<<endl;
    return 0;
}






// int main()
// {
// 	int n, tm;
// 	cin>>n;
// 	int a[n+2], m[n+2][n+2][2];
// 	a[0] = 1; a[n+1] = 1;
// 	for (int i = 1; i < n+1; ++i)
// 		cin>>a[i];
// 	for (int i = 0; i < n+1; ++i)
// 		m[i+1][i][0] = 0;
// 	for (int i = 1; i < n+1; ++i){
// 		for (int j = 0; j < n+1-i; ++j){
// 			m[j+1][i+j][0] = 0;
// 			for (int k = j+1; k < i+j+1; ++k){
// 				tm = m[j+1][k-1][0] + a[j+1-1]*a[k]*a[i+j+1] +m[k+1][i+j][0];
// 				if(tm > m[j+1][i+j][0]){
// 					m[j+1][i+j][0] = tm;
// 					m[j+1][i+j][1] = k;
// 				}
// 			}
// 		}
// 	}
// 	cout<<m[1][n][0]<<endl;
//     return 0;
// }