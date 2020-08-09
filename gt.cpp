#include <iostream> 
#include <map> 
using namespace std;



int main() { 
    int t, n, s, i;
    cin>>t;
    while(t--){
        map<int, int> mp;
        cin>>n;
        int a[n];
        for (i = 0; i < n; ++i)
            cin>>a[i];
        cin>>s;
        for (i = 0; i < n; ++i)
            mp[a[i]%s]++;
        for (i = 0; i < n; ++i)
            if(mp[a[i]%s]!=mp[(s-(a[i]%s))%s])
                break;
        cout<<((i==n) ? "True" : "False")<<endl; 
    }  
    return 0; 
}

