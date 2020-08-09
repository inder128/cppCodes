#include <iostream> 
#include <stack> 
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, ta, m, w=0, tw, x, y;
		stack <int> s; 
		cin>>n;
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		b[0]=0;
		for (int i = 1; i < n; ++i)
			b[i] = max(a[i-1], b[i-1]);
		s.push(0);
		for (int i = 1; i < n; i++){
			if(a[i]>=b[i]){
				while(a[s.top()]<b[i]) s.pop();
				s.push(i);
			}
			else if(s.empty() or a[s.top()]>=a[i]){
				s.push(i);
			}
			else{
				ta = s.top();
				s.pop();
				while(!s.empty() and a[s.top()]<=a[i]){
					ta = s.top();
					s.pop();
				} 
				if(s.empty()) s.push(ta);
				s.push(i);
			}
		}
		y = s.top(); s.pop();
		while(!s.empty()){
			tw = 0; 
			x = s.top(); s.pop();
			m = min(a[x], a[y]);
			for (int i = x+1; i < y; ++i)
				tw += m-a[i];
			w +=tw;
			y = x; 
		}
		cout<<w<<endl;
	}
    return 0;
}




// void showstack(stack <int> s){ 
//     while (!s.empty()){ 
//         cout<<s.top()<<'\t'; 
//         s.pop(); 
//     } 
//     cout<<'\n'; 
// }

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, ta, m, w=0, tw, x, y;
// 		stack <int> s; 
// 		cin>>n;
// 		int a[n], b[n];
// 		for (int i = 0; i < n; ++i)
// 			cin>>a[i];
// 		b[0]=0;
// 		for (int i = 1; i < n; ++i)
// 			b[i] = max(a[i-1], b[i-1]);
// 		for (int i = 0; i < n; ++i)
// 			cout<<b[i]<<' ';
// 		cout<<endl;
// 		s.push(0);
// 		for (int i = 1; i < n; i++){
// 			showstack(s);
// 			if(a[i]>=b[i]){
// 				cout<<i<<" a"<<endl;
// 				while(a[s.top()]<b[i]) s.pop();
// 				s.push(i);
// 			}
// 			else if(s.empty() or a[s.top()]>=a[i]){
// 				cout<<i<<" b"<<endl;
// 				s.push(i);
// 			}
// 			else{
// 				cout<<i<<" c"<<endl;
// 				ta = s.top();
// 				s.pop();
// 				while(!s.empty() and a[s.top()]<=a[i]){
// 					ta = s.top();
// 					s.pop();
// 				} 
// 				if(s.empty()) s.push(ta);
// 				s.push(i);
// 			}
// 		}
// 		showstack(s);
// 		y = s.top(); s.pop();
// 		while(!s.empty()){
// 			tw = 0; 
// 			x = s.top(); s.pop();
// 			m = min(a[x], a[y]);
// 			cout<<x<<" x y "<<y<<endl;
// 			for (int i = x+1; i < y; ++i)
// 				tw += m-a[i];
// 			w +=tw;
// 			y = x; 
// 		}
// 		cout<<w<<endl;
// 	}
//     return 0;
// }