#include <iostream> 
#include <string>
using namespace std;

int fact(int n) 
{ 
    if (n == 0) 
        return 1; 
    return n * fact(n - 1); 
}

int p(int a[]){
	int t=0;
	for (int i = 0; i < 26; ++i)
		t += a[i];
	t = fact(t);
	for (int i = 0; i < 26; ++i)
		t /= fact(a[i]);
	return t;
}

string nthword(string s, int n){
	int t, a[26], f;
	for (int i = 0; i < 26; ++i) a[i]=0;
	f = 0;
	for (int i = 0; i < s.length(); ++i)
		a[s[i]-'a']++;
	while(f<s.length()){
		// printf("f: %d \n", f);
		for (int i = 0; i < 26; ++i){
			if(a[i]==0) continue;
			a[i]--;
			// printf("i: %d   p(a): %d   n: %d \n", i, p(a), n);
			if(n>p(a)){
				n -= p(a);
				a[i]++;
			}
			else{
				s[f] = 'a' + i;
				f++;
				break;
			}
		}
	}
    return s;
}


int main(){
	int t, a[26], f;
	string s;
	cin>>t;
	while(t--){
		for (int i = 0; i < 26; ++i) a[i]=0;
		cin>>s;
		for (int i = 0; i < s.length(); ++i)
			a[s[i]-'a']++;
		f = p(a);
		for (int i = 1; i < f+1; ++i)
			cout<<nthword(s, i)<<" ";
		cout<<endl;
	}
    return 0;
}