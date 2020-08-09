#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin>>t;
	queue <char> q1,q2;
	while(t--){
		int n;
		cin>>n;
		char ca[n], c;
		int a[26];
		for (int i = 0; i < 26; ++i)
			a[i]=0;
		for (int i = 0; i < n; i++){
			cin>>c;
			if(a[c-'a']==0){
				a[c-'a']++;
				q1.push(c);
				ca[i] = q1.front();
			}
			else if(a[c-'a']==1){
				a[c-'a']++;
				while(!q1.empty()){
					if(q1.front()!=c) q2.push(q1.front());
					q1.pop();
				}
				while(!q2.empty()){
					q1.push(q2.front());
					q2.pop();
				}
				ca[i] = ((q1.empty()) ? '?' : q1.front());
			}
			else
				ca[i] = ((q1.empty()) ? '?' : q1.front());	
		}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		for (int i = 0; i < n; ++i){
			if(ca[i]=='?')
				cout<<"-1 ";
			else
				cout<<ca[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}