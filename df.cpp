// 2+1 string matching problem

#include <iostream> 
#include <stack> 
#include <string> 

using namespace std; 

int main()
{
	int n;
	stack <char> s;
	cin>>n;
	string sa[n];
	for (int i = 0; i < n; ++i)
		cin>>sa[i];
	char c;
	for (int j = 0; j < n; ++j){
		for (int i = 0; i < sa[j].length(); ++i){
			c = sa[j][i];
			if (s.empty() or c=='{' or c=='[' or c=='(')  
				s.push(c);
			else if ((s.top()=='{' and c=='}') or (s.top()=='[' and c==']') or (s.top()=='(' and c==')'))
				s.pop();
			else 
				s.push(c);
		}
		cout<<((s.empty()) ? "balanced\n" : "not balanced\n");
		while(!s.empty()) s.pop();
	}	
    return 0;
}