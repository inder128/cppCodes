#include <iostream>
using namespace std;

void prin(int ab[], int n){
    cout<<"[";
    for (int i = 1; i <= n; ++i)
        cout<<ab[i]<<" ";
    cout<<"] "; 
}

void fun(int ab[], int ba[], int y[], int l[], int n, int i, pair <int, int> p[]){
    if(i==0) return;
    if (i==n+1){
        prin(ab, n);
        return fun(ab, ba, y, l, n, i-1, p); 
    }
    y[p[i].first] = 0;  l[p[i].second] = 0;
    int j;
    for (j = ab[i]+1; j <= n; ++j)
        if(ba[j]==0 and y[i+j-1]==0 and l[j-i+n]==0){
            p[i] = make_pair(((y[i+j-1]) ? 0 : i+j-1), ((l[j-i+n]) ? 0 : j-i+n));
            ba[ab[i]] = 0;  ab[i] = j;  ba[j] = i;
            y[i+j-1]=1;  l[j-i+n]=1;
            return fun(ab, ba, y, l, n, i+1, p); 
            break;
        }
    if(j==n+1){
        p[i] = make_pair(0, 0);
        ba[ab[i]] = 0;  ab[i] = 0;
        return fun(ab, ba, y, l, n, i-1, p); 
    } 
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int ab[n+1], ba[n+1], l[2*n], y[2*n];
        pair <int, int> p[n+1];
        for (int i = 0; i <= n; ++i){
            ab[i]=0;
            ba[i]=0;
            p[i] = make_pair(0,0);
        }
        for (int i = 0; i < 2*n; ++i){
            l[i]=0;
            y[i]=0;
        }
        if(n==2 or n==3) cout<<"-1";
        fun(ab, ba, y, l, n, 1, p);
        cout<<endl; 
    }
    return 0;
}


// void print(int ab[], int ba[], int y[], int l[], int n, int i, int j, pair <int, int> p[]){
//     printf("\nn=%d i=%d j=%d", n, i, j);
//     printf("\nab[]\n");
//     for (int i = 0; i <= n; ++i)
//         cout<<ab[i]<<" ";
//     printf("\nba[]\n");
//     for (int i = 0; i <= n; ++i)
//         cout<<ba[i]<<" ";
//     printf("\np[]\n");
//     for (int i = 0; i <= n; ++i)
//         cout<<p[i].first<<" "<<p[i].second<<"    ";
//     printf("\ny[]\n");
//     for (int i = 0; i < 2*n; ++i)
//         cout<<y[i]<<" ";
//     printf("\nl[]\n");
//     for (int i = 0; i < 2*n; ++i)
//         cout<<l[i]<<" ";
//     cout<<"\n"; 
// }

// void fun(int ab[], int ba[], int y[], int l[], int n, int i, pair <int, int> p[]){
//     // cout<<"cc\n"<<endl; 
//     if(i==0) return;
//     if (i==n+1){
//         // cout<<"pp\n"<<endl; 
//         prin(ab, n);
//         return fun(ab, ba, y, l, n, i-1, p); 
//     }
//     y[p[i].first] = 0;  l[p[i].second] = 0;
//     int j;
//     for (j = ab[i]+1; j <= n; ++j){
//         if(ba[j]==0 and y[i+j-1]==0 and l[j-i+n]==0){
//             // cout<<"dd\n"<<endl;
//             // print(ab, ba, y, l, n, i, j, p); 

//             p[i] = make_pair(((y[i+j-1]) ? 0 : i+j-1), ((l[j-i+n]) ? 0 : j-i+n));
//             ba[ab[i]] = 0;  ab[i] = j;  ba[j] = i;
//             y[i+j-1]=1;  l[j-i+n]=1;
//             // print(ab, ba, y, l, n, i, j, p); 
//             return fun(ab, ba, y, l, n, i+1, p); 
//             break;
//         }
//     }
//     if(j==n+1){
//         // cout<<"ff\n"<<endl;
//         // print(ab, ba, y, l, n, i, j, p); 
//         p[i] = make_pair(0, 0);
//         ba[ab[i]] = 0;  ab[i] = 0;
//         // print(ab, ba, y, l, n, i, j, p);
//         return fun(ab, ba, y, l, n, i-1, p); 
//     } 
// }