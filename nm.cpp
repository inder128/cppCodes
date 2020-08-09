// rod cutting problem
#include <iostream> 
using namespace std; 

int main()
{
	int t, l, n, i;
	cin>>t;
	while(t--){
		l = 0;
		cin>>n;
		string s[n];
		for (i = 0; i < n; ++i)
			cin>>s[i];
		while(1){
			for (i = 1; i < n; ++i)
				if(s[i-1][l]==' ' or s[i-1][l] != s[i][l])
					break;
			if(i==n) l++;
			else break;
			
		}
		for (i = 0; i < l; ++i)
			cout<<s[0][i];
		cout<<endl;
	}
    return 0;
}