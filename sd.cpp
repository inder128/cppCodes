// 2+1 string matching problem

#include <iostream> 
#include <stack> 

using namespace std; 

int main()
{
	long long int t, l, ti;
	cin>>t;
	stack <long long int> s;
	for (long long int j = 0; j < t; ++j){
		cin>>l;
		long long int a[l+1], r[l];
		a[l] = -1;
		for (long long int i = 0; i < l; ++i)
			cin>>a[i];
		ti = 0;
		while(ti<l)
			if(s.empty() or a[s.top()]>a[ti]) {s.push(ti++); continue;}
			else {r[s.top()] = ti;  s.pop();}
		while(!s.empty()) {r[s.top()] = l;  s.pop();}
		for (long long int i = 0; i < l; ++i)
			cout<<a[r[i]]<<" ";
		cout<<endl;
	}	
    return 0;
}