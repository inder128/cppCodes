# include <bits/stdc++.h>
using namespace std;

void showstack(stack <int> s) 
{ 
	cout<<s.size()<<"\n";
    while (!s.empty()) 
    { 
        cout<<s.top()<<" "; 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		stack <int> q; 
		int n;
		cin>>n;
		int i=1;
		int top;
		q.push(n);
		while(n/i)
		{
			top=q.top();
			if(n/i!=top)
			{
				q.push(n/i);
			}
			i++;
		}
		q.push(0);
		showstack(q);
	}
    return 0;
}