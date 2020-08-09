// { Driver Code Starts
#include<iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
    int s=0, e=1, cp = p[0].petrol - p[0].distance;
    while(s<n){
        if(cp<0){
            cp = cp - (p[s].petrol - p[s].distance);
            s++;
        } else{
            cp = cp + (p[e].petrol - p[e].distance);
            e++;
            e = e%n;
            if(s==e and cp>0) break;
        }
    }
    return (s==n) ? -1 : s;
}

// IN T(n^2) TIME COMPLEXITY :-
// int e, ti, tim, td, i;
// for (i = 0; i < n; ++i){
//     e = 0;
//     for (int j = 1; j <= n; ++j){
//           ti = (i+j)%n;
//           tim = (i+j-1)%n;
//           if(e==-1) continue;
//           td = (e+p[tim].petrol) - p[tim].distance;
//           e = (td >= 0) ? td : -1;
//     }
//     if (e>=0) break; 
// }
// return (e>=0) ? i : -1;




// IN T(n) TIME COMPLEXITY AND SIMPLER METHOD :- 
// int start=0, deficit=0, capacity=0;
// for(int i=0;i<n;i++)
// {
//    capacity+=p[i].petrol-p[i].distance;
//    if(capacity<0){
//        start=i+1;
//        deficit+=capacity;
//        capacity=0;
//    }
// }
// return(capacity+deficit>0)?start:-1;











