#include <iostream> 
#include <string> 
using namespace std;

bool rtf(int aa[], int ab[]){
    for (int i = 0; i < 26; ++i)
        if(ab[i] > aa[i]) return false;
    return true;
}

int main() { 
    int t, n, m, i, j, aa[26], ab[26];
    cin>>t;
    while(t--){        
        string sa, sb;
        cin>>sa>>sb;
        n = sa.length();
        m = sb.length();
        for (i = 0; i < 26; ++i) ab[i]=0;
        for (i = 0; i < m; ++i)
            ab[sb[i]-'a']++;
        for (i = m; i <= n; ++i){
            for (j = 0; j < 26; ++j) aa[j]=0;
            for (j = 0; j < i; ++j)
                aa[sa[j]-'a']++;
            j=0;
            if(rtf(aa, ab)) break;
            for (j = 1; j <= n-i; ++j){
                aa[sa[j-1]-'a']--; aa[sa[j+i-1]-'a']++;
                if(rtf(aa, ab)) break;
            }
            if(j!=n-i+1) break;
        }
        if(i==n+1 or n<m)
            cout<<"-1";
        else
            for (int k = j; k <= j+i-1; ++k)
                cout<<sa[k];
        cout<<endl;
    }  
    return 0; 
}