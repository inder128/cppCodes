#include <iostream> 
#include <iterator> 
#include <map> 
using namespace std;

bool comp1gs(pair<int, int> p1, pair<int, int> p2){
    if(p1.first==p2.first)
        return (p1.second<p2.second);
    return (p1.first>p2.first); 
}

int main() { 
    int t, n, l, i;
    cin>>t;
    while(t--){
        map<int, int> mp;
        cin>>n;
        int a[n], c=0;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            mp[a[i]]++;
        }
        l = mp.size(); i=0;
        pair <int, int> p[l];
        map<int, int>::iterator itr; 
        for (itr = mp.begin(); itr != mp.end(); ++itr)
            p[i++] = make_pair(itr->second, itr->first);
        sort(p, p+l,  comp1gs);
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < p[i].first; ++j)
                cout<<p[i].second<<" ";
        cout<<endl;
    }  
    return 0; 
}


