#include <map>
#include <iostream> 
#include <string>
using namespace std;

int main(){
	map <char,int> rmn = {
	    { 'I', 1 },
	    { 'V', 5 },
	    { 'X', 10 },
	    { 'L', 50 },
	    { 'C', 100 },
	    { 'D', 500 },
	    { 'M', 1000 }
	};
	int t, l, m;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		l = s.length();
		m = 0;
		for (int i = 0; i < l-1; ++i) {
			if(rmn[s[i]]<rmn[s[i+1]]) 
				m -= rmn[s[i]];
			else
				m += rmn[s[i]];
		}
		m += rmn[s[l-1]];
		cout<<m<<endl;
	}
	return 0;
}