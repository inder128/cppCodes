// Maximum Size Rectangle of All 1's problem

#include <iostream> 
#include <string>

using namespace std; 

int main()
{
	int n=12;
	string sa[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
	string s;
	cin>>s;
	int a[s.length()+1];
	a[s.length()] = 1;
	for (int i = s.length()-1 ; i >= 0; --i){
		a[i] = 0;
		for (int j = 0; j < n; ++j){
			if(sa[j]==s.substr(i, sa[j].length()))
				a[i] = a[i] or a[i+sa[j].length()];
		}
	}
	cout<<(a[0] ? "\nYes" : "\nNo");
    return 0;
}