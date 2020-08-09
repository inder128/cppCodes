#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k;
vector<vector<pair<int,int> > >v(N),d(N);
vector<int>res;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		int l,r;
		cin>>l>>r;
		v[l].push_back(make_pair(r,i));
		d[r+1].push_back(make_pair(r,i));
	}
	set<pair<int,int> >st;
	for(int i=0;i<2e5+1;++i){
		for(auto&p:d[i])st.erase(p);
		for(auto&p:v[i])st.insert(p);
		while(st.size()>k){
			res.push_back((*--st.end()).second);
			st.erase(--st.end());
		}
	}
	cout<<res.size()<<'\n';
	for(auto&el:res)cout<<el+1<<' ';
}