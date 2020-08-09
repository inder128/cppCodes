#include <iostream> 
#include <map> 

using namespace std; 

int main() { 
    int t, n, m;
    cin>>t;
    while(t--){
        map<int, int> mp;
        cin>>n>>m;
        int a[n], b[m];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        for (int i = 0; i < m; ++i){
            cin>>b[i];
            mp[b[i]]=1;
        }
        for (int i = 0; i < n; ++i){
            if(mp[a[i]]) mp[a[i]]++;
            else a[i] *= -1;
        }
        sort(a, a+n);
        for (int i = 0; i < m; ++i)
            for (int j = 1; j < mp[b[i]]; ++j)
                cout<<b[i]<<" ";
        for (int i = n-1; i >= 0; --i)
            if(a[i]<0) cout<<-1*a[i]<<" ";
        cout<<endl;
    }  
    return 0; 
} 
