// Weighted Job Scheduling problem

#include <iostream> 

using namespace std; 

int main()
{
	int n;
	cin>>n;
	int s[n], e[n], v[n], r[n];
	for (int i = 0; i < n; ++i)
		cin>>s[i]>>e[i]>>v[i];
	for (int i = 0; i < n; ++i)
		r[i] = v[i];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			r[i] = max(r[i], ((e[j]<=s[i]) ? r[j]+v[i] : r[j]));				
	cout<<r[n-1]<<endl;
    return 0;
}






// int main()
// {
// 	int n, c=0;
// 	cin>>n;
// 	int a[n+1][3];
// 	for (int i = 1; i < n+1; ++i)
// 		cin>>a[i][0]>>a[i][1]>>a[i][2];
// 	a[0][0] = 0; a[0][1] = 0; a[0][2] = 0;
// 	int l[a[n][1]+1], r[a[n][1]+1];
// 	for (int i = 1; i < n+1; ++i, c++)
// 		for (int j = a[i-1][1]; j < a[i][1]; ++j)
// 			l[j] = c;
// 	l[a[n][1]] = c;
// 	for (int i = 0; i < a[1][1]; ++i)
// 		r[i] = 0;
// 	for (int i = a[1][1]; i < a[n][1]+1; ++i)
// 		r[i] = max(a[l[i]][2] + r[a[l[i]][0]], r[a[l[i]-1][1]]);
// 	cout<<r[a[n][1]]<<endl;
//     return 0;
// }