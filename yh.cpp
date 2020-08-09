#include <iostream> 
#include <map> 
using namespace std;



int main() { 
    int t, n, m, mm;
    cin>>t;
    while(t--){
        m=0; mm=0;
        map<int, int> mp;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            mp[a[i]]=1;
            m = max(m, a[i]);
        }
        int b[m+1]; 
        b[0] = mp[0];
        for (int i = 1; i <= m; ++i)
            if(mp[i]) mp[i]=mp[i-1]+1;
        for (int i = 1; i <= m; ++i)
            mm = max(mm, mp[i]);
        cout<<mm<<endl; 
    }  
    return 0; 
}

