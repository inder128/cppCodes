// buy/sell maximising problem

#include <iostream> 

using namespace std; 

long long int md(long long int a[2], long long int b[2]){
	return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}

int main()
{
	long long int n, t=0, s, ts, tts, tc, tj;
	cin>>n;
	long long int a[10*n][2], b[10*n][2], c[10*n];
	for (int i = 0; i < n; ++i){
		cin>>a[t][0]>>a[t][1]>>tc;
		for (int i = 1; i < tc; ++i){
			a[t+i][0] = a[t][0];
			a[t+i][1] = a[t][1];
		}
		t += tc;			
	}
	t = 0;
	for (int i = 0; i < n; ++i){
		cin>>b[t][0]>>b[t][1]>>tc;
		for (int i = 1; i < tc; ++i){
			b[t+i][0] = b[t][0];
			b[t+i][1] = b[t][1];
		}
		t += tc;			
	}
	s = md(a[0], b[0]);
	c[0] = 0;
	for (int i = 1; i < t; ++i){
		ts = md(a[i], b[i]);
		tj = i;
		for (int j = 0; j < i; ++j){
			if ((md(a[j], b[i]) + md(a[i], b[c[j]]) - md(a[j], b[c[j]])) > ts){
				ts = md(a[j], b[i]) + md(a[i], b[c[j]]) - md(a[j], b[c[j]]);
				tj = j;
			}
		}
		c[i] = c[tj];
		c[tj] = i;
		s += ts;
		// cout<<i<<" : "<<s<<"   ";
	}
	cout<<endl;
	for (int i = 0; i < t; ++i){
		cout<<i<<" : "<<c[i]<<"   ";
	}
	// cout<<endl;
	// for (int i = 0; i < t; ++i){
	// 	cout<<a[i][0]<<" : "<<a[i][1]<<"    ";
	// }
	// cout<<endl;
	// for (int i = 0; i < t; ++i){
	// 	cout<<b[i][0]<<" : "<<b[i][1]<<"    ";
	// }
	// cout<<endl;
	cout<<s<<endl;
    return 0;
}