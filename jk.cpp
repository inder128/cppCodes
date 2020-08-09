#include<iostream>
#include<queue>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, i ,j;
        cin>>n>>m;
        int a[n+2][m+2];
        queue <pair<int,int> > q;
        pair<int,int> p;
        memset(a, 0, sizeof(a)); 
        for (i = 1; i < n+1; ++i){
            for (j = 1; j < m+1; ++j){
                cin>>a[i][j];
                if(a[i][j]==2) q.push(make_pair(i,j));     
            }
        }
        q.push(make_pair(0,0));
        while(!q.empty()){
            p = q.front(); q.pop();
            i = p.first;  j = p.second;
            if(j==0){
                if(q.empty()) break;
                q.push(make_pair(i+1,j));
                continue;
            }
            if(a[i][j-1]==1){
                a[i][j-1] = 2;
                q.push(make_pair(i,j-1));
            }
            if(a[i-1][j]==1){
                a[i-1][j] = 2;
                q.push(make_pair(i-1,j));
            }
            if(a[i][j+1]==1){
                a[i][j+1] = 2;
                q.push(make_pair(i,j+1));
            }
            if(a[i+1][j]==1){
                a[i+1][j] = 2;
                q.push(make_pair(i+1,j));
            }
        }
        for (int ij = 1; ij < n+1; ++ij){
            for (j = 1; j < m+1; ++j){
                if(a[ij][j]==1){
                    i = -1;
                    break;
                }
            }
        }
        cout<<i<<endl;
    }
}
