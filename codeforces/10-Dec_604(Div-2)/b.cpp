# include <bits/stdc++.h>
using namespace std;
int v[10][10][10][10][2];
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				for (int k = 0; k < 10; ++k)
					for (int l = 0; l < 10; ++l)
						v[i][j][k][l][0]=0;
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				for (int k = 0; k < 10; ++k)
					for (int l = 0; l < 10; ++l)
						v[i][j][k][l][1]=-1;

		cin>>n;
		char a[4*n];
		int s=0;
		int j=0;
		char q,w,e,r;
		for (int i = 0; i < n; ++i)
		{
			cin>>q>>w>>e>>r;
			if(!v[q-'0'][w-'0'][e-'0'][r-'0'][0])
			{
				v[q-'0'][w-'0'][e-'0'][r-'0'][0]=1;
				v[q-'0'][w-'0'][e-'0'][r-'0'][1]=i;
			}
			a[j]=q; a[j+1]=w; a[j+2]=e; a[j+3]=r; j=j+4;
		}
		for (int i = 0; i < 4*n; i=i+4)
		{
			q=a[i]; w=a[i+1]; e=a[i+2]; r=a[i+3];
			if(v[q-'0'][w-'0'][e-'0'][r-'0'][0] and v[q-'0'][w-'0'][e-'0'][r-'0'][1]!=i/4)
			{
				s=s+1;
				for (int i = 0; i < 10; ++i)
				{
					if(!v[q-'0'][w-'0'][e-'0'][i][0])
					{
						r=digits[i];
						break;
					}
				}
			}
			a[i+3]=r;
			v[q-'0'][w-'0'][e-'0'][r-'0'][0]=1;
			v[q-'0'][w-'0'][e-'0'][r-'0'][1]=i/4;
		}

		cout<<s<<"\n";
		for (int i = 0; i < 4*n; i=i+4)
			cout<<a[i]<<a[i+1]<<a[i+2]<<a[i+3]<<"\n";
	}
    return 0;
}