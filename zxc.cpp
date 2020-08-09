// box stacking problem

#include <iostream> 

using namespace std; 

void addarr(int a[][3], int m, int h, int w, int l){
	int bi;
	for (int i = 0; i < 3*m+1; ++i)
		if (a[i][1]<=w && a[i][2]<=l){
			bi=i; break;
		}
	for (int i = 3*m+1; i > bi; --i){
		a[i][0]=a[i-1][0]; a[i][1]=a[i-1][1]; a[i][2]=a[i-1][2]; 
	}
	a[bi][0]=h; a[bi][1]=w; a[bi][2]=l;

	for (int i = 0; i < 3*m+2; ++i)
		if (a[i][1]<=l && a[i][2]<=h){
			bi=i; break;
		}
	for (int i = 3*m+2; i > bi; --i){
		a[i][0]=a[i-1][0]; a[i][1]=a[i-1][1]; a[i][2]=a[i-1][2]; 
	}
	a[bi][0]=w; a[bi][1]=l; a[bi][2]=h;

	for (int i = 0; i < 3*m+3; ++i)
		if (a[i][1]<=h && a[i][2]<=w){
			bi=i; break;
		}
	for (int i = 3*m+3; i > bi; --i){
		a[i][0]=a[i-1][0]; a[i][1]=a[i-1][1]; a[i][2]=a[i-1][2]; 
	}
	a[bi][0]=l; a[bi][1]=h; a[bi][2]=w;
}

int main()
{
	int n, h, w, l, k;
	cin>>n;
	int a[3*n+1][3], m[3*n+1];
	a[0][0]=0; a[0][1]=0; a[0][2]=0; 
	for (int i = 0; i < n; ++i){
		cin>>h>>w>>l;
		addarr(a, i, h, w, l);
	}
	m[3*n]=0;
	for (int i = 3*n-1; i >= 0; --i){
		for (int j = i+1; j < 3*n+1 ; ++j)
			if(a[j][1]<a[i][1] && a[j][2]<a[i][2]){ k=j; break; }
		m[i] = max(m[i+1], m[k]+a[i][0]);
	}
	cout<<m[0]<<endl;
    return 0;
}