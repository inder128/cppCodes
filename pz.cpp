#include <iostream> 
#include <stack> 
#include <queue> 
using namespace std;

int main(){
	int t;
	stack <char> stk;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		for (int i =  s.length()-1; i >= 0; --i){
			if(s[i]!='.') stk.push(s[i]);
			else{
				while(!stk.empty()){
					cout<<stk.top();
					stk.pop();
				}
				cout<<'.';
			}
		}
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
    return 0;
}