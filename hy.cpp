#include <iostream> 
#include <map> 
using namespace std;



int main() { 
    int t, n, s;
    cin>>t;
    while(t--){
        s=0;
        map<int, int> mp;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        mp[a[0]]=1;
        if(a[0]==0) s++;
        for (int i = 1; i < n; ++i){
            a[i] = a[i-1]+a[i];
            if(a[i]==0) s++;
            s += mp[a[i]];
            mp[a[i]]++;
        }
        cout<<s<<endl; 
    }  
    return 0; 
}

