// rod cutting problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, s, m;
	cin>>n>>s;
	int c[n];
	for (int i = 0; i < n; ++i)
		cin>>c[i];
	int co[n];
	for (int i = 0; i < s; ++i){
		co[i] = 0;
		for (int j = 0; j < n; ++j)
			co[i] += ((i-c[j]>=0) ? co[i-c[j]]+1 : 0);
		co[i] = m;
	}
	cout<<co[s-1]<<endl;
    return 0;
}