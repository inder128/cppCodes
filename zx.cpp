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

int main(){
	int t, a[26], f, n;
	string s;
	cin>>t;
	while(t--){
		for (int i = 0; i < 26; ++i) a[i]=0;
		f = 0;
		cin>>n;
		cin>>s;
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
		cout<<s<<endl;
	}
    return 0;
}