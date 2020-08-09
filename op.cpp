#include <iostream> 
#include <stack> 
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1], b[n+1];
		stack <pair<int, int> > st;
		for (int i = 1; i < n+1; ++i)
			cin>>a[i];
		a[0] = 0; b[0] = 0; b[1] = 0;
		b[2]= ((a[2]-a[1]>0) ? a[2]-a[1] : 0);
		for (int i = 3; i < n+1; ++i){
			b[i] = b[i-1]; 
			for (int j = 1; j < i; ++j)
				b[i] = max(b[i], b[j-1] + a[i]-a[j]);
		}
		int t=n, s;
		while(t>=2){
			if(b[t]==b[t-1]){
				t--;
				continue;
			}
			s=t-1;
			while(b[s-1]+a[t]-a[s]!=b[t])  
				s--;
			st.push(make_pair(s-1,t-1));
			
			t = s-1;
		}
		if(st.empty()){
			cout<<"No Profit\n";
			continue;
		}
		while(!st.empty()){
			printf("(%d %d) ",st.top().first,st.top().second);
			st.pop();
		}
		cout<<endl;
	}
    return 0;
}