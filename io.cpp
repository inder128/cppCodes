#include <iostream> 
#include <math.h> 
using namespace std;

int ndigit(int n){ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

int bos(int a, int b){ 
	int aa = a*pow(10, ndigit(b)) + b;
	int bb = b*pow(10, ndigit(a)) + a;
	return aa<bb;
}

void arng(int a[], int n){
	int t = a[n];
	for (int i = 0; i < n; ++i)
		if(bos(a[i], a[n]))
			for (int j = n; j > i; --j)
				swap(a[j-1], a[j]);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m=0;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		for (int i = 1; i < n; ++i)
			arng(a, i);
		for (int i = 0; i < n; ++i)
			cout<<a[i];
		cout<<endl;
	}
    return 0;
}