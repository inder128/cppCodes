// longest commen subsequence by dynamic programming

#include <iostream> 

using namespace std; 

int main(){
	int n, m;
	cin>>n>>m;
	char a[n+1];
	char b[m+1];
	cin>>a;
	cin>>b;
	int ab[n+1][m+1];
	for (int i = 0; i < n+1; ++i)
		ab[i+1][0]=0;
	for (int i = 0; i < m+1; ++i)
		ab[0][i+1]=0;
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < m+1; ++j)
			ab[i][j] = (a[i-1]==b[j-1] ? ab[i-1][j-1]+1 : max(ab[i-1][j], ab[i][j-1]));
	cout<<ab[n][m]<<endl;
	int i=n, j=m, p=ab[n][m]-1;
	char s[ab[n][m]];
	while(i!=0 and j!=0){
		if(a[i-1]==b[j-1])
			s[p--] = a[i-1];
		else if(ab[i][j] == ab[i-1][j])
			j++;
		else
			i++;
		i--; j--;
	}
	cout<<s<<endl;
    return 0;
}