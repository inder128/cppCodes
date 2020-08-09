#include <iostream> 
#include <stack> 
#include <set> 
using namespace std;

struct comp {
    bool operator() (int a[], int b[]) const
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else{
            if(a[1]!=b[1])
                return a[1]<b[1];
            else{
                if(a[2]!=b[2])
                    return a[2]<b[2];
                else
                    return a[3]<b[3];
            }
        }
    }
};

stack <pair<int, int> > acof(int a[], int n, int s){
    int i=0, j=n-1, ts, t=0;
    stack <pair<int, int> > st;
    while(i<j){
        ts = a[i] + a[j];
        if(ts<s) i++;
        else if(ts>s) j--;
        else st.push(make_pair(i++, j));
    }
    return st;
}

int main() { 
    int t, n, s, w, x, y, z;
    cin>>t;
    while(t--){
        set<int*, comp> st;
        stack <pair<int, int> > stk1, stk2, stk3;
        cin>>n>>s;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        sort(a, a+n);
        for (int i = 0; i <= s/2; ++i){
            stk1 = acof(a, n, i);
            stk2 = acof(a, n, s-i);
            stk3 = stk2;
            while(!stk1.empty()){
                w = stk1.top().first;
                x = stk1.top().second;
                stk1.pop();
                while(!stk2.empty()){
                    y = stk2.top().first;
                    z = stk2.top().second;
                    stk2.pop();
                    if(w!=y and w!=z and x!=y and x!=z){
                        int *ta = new int[4];
                        ta[0]=a[w]; ta[1]=a[x]; ta[2]=a[y]; ta[3]=a[z];
                        sort(ta, ta+4);
                        st.insert(ta);
                    }
                }
                stk2 = stk3;
            }
            while(!stk1.empty()) stk1.pop();
            while(!stk2.empty()) stk2.pop();
            while(!stk3.empty()) stk3.pop();
        }
        if(st.size()==0) cout<<"-1";
        set <int* , comp> :: iterator itr; 
        for (itr = st.begin(); itr != st.end(); ++itr) 
            cout<<(*itr)[0]<<" "<<(*itr)[1]<<" "<<(*itr)[2]<<" "<<(*itr)[3]<<" $ ";
        cout<<endl; 
    }  
    return 0; 
}