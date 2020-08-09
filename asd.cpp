// longest length of valid paranthesis substring

#include <iostream> 
#include <string> 
#include <stack> 

using namespace std; 

int main()
{
	string s;
	cin>>s;
	int a[s.length()];
	int ml = 0, tml=0, it = 0;
	stack <int> stk; 
	for (int i = 0; i < s.length(); ++i)
		a[i] = 0;
	for (int i = 0; i < s.length(); ++i){
		if(s[i]=='('){
			stk.push(i);
		} else if(!stk.empty()){
			a[stk.top()] = i;
			stk.pop();
		}
	}
	while(it<s.length()){
		if(!a[it]){
			it++;
			continue;
		}
		while(a[it] and it<s.length()){
			tml += a[it] - it + 1;
			it = a[it] + 1;
		}
		if(tml>ml)
			ml = tml;
		tml = 0;
	}
	cout<<ml<<endl;
    return 0;
}