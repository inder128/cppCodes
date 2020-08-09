// histogram problem
// printf("area:%d, si:%d, ei:%d, h:%d",marea,si,ei,h);
#include <iostream> 
#include <stack>

using namespace std; 

int main()
{
	int n, i=0, top, area, marea=0, si, ei, h;
	stack <int> s;
	cin>>n;
	int a[n]; 
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	while(i<n or !s.empty()){
		if (i<n and (s.empty() or a[s.top()]<=a[i])){ 
			s.push(i++); 
			continue; 
		}
		while(!s.empty() and (i==n or a[s.top()]>a[i])){
			top = s.top(); s.pop();
			area = ((s.empty()) ? a[top]*i : a[top]*(i-s.top()-1));
			if(area>marea){
				marea=area;
				si = ((s.empty()) ? 0 : s.top()+1);
				ei = i-1;
				h = a[top];
			}  
		}
	}
	cout<<marea<<endl;
	printf("area:%d, si:%d, ei:%d, h:%d",marea,si,ei,h);
    return 0;
}