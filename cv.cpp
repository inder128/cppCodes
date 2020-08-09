#include <iostream> 
#include <string>
using namespace std;

string smpl(string s){
	string ss = "";
	int l = s.length();
	if(l==1 or s[0]!=s[1]) 
		ss += s[0];
	for (int i = 1; i < l-1; ++i)
	 	if(s[i]!=s[i-1] and s[i]!=s[i+1])
	 		ss += s[i];
	if(l>1 and s[l-1]!=s[l-2]) 
		ss += s[l-1]; 
	if(ss==s)
		return s;
	else
		return smpl(ss);

}

int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<smpl(s)<<endl;
	}
    return 0;
}


