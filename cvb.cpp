// rod cutting problem

#include <iostream> 

using namespace std; 

int main()
{
	int n, m;
	cin>>n;
	int p[n];
	for (int i = 0; i < n; ++i)
		cin>>p[i];
	int po[n];
	for (int i = 0; i < n; ++i){
		m = p[i];
		for (int j = 0; j < i; ++j)
			m = max(po[j]+p[i-j-1] , m);
		po[i] = m;
	}
	cout<<po[n-1]<<endl;
    return 0;
}