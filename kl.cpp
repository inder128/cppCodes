#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        deque <int> q;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        for (int i = 0; i < n; ++i){            
            while(1){
                if(q.empty() or a[q.back()]>a[i]){
                   q.push_back(i);
                   break;
                }
                else{
                   q.pop_back();  
                }
            }
            if(i>=k-1){
                if((i-k)==q.front()) q.pop_front();
                cout<<a[q.front()]<<" ";
            } 
        }
        cout<<endl;
    }
}