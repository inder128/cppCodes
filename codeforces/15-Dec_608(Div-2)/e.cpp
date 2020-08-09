# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	int a[n] , b[n] , c[n] , u[m] , v[m];
	int uv[n+1][n+1];
	int sparesoldiers[n] , extrasoldiers[n];
	vector <pair<int, int> > pandi;

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
			uv[i][j]=0;
		uv[i][i]=1;
	}
	pandi.push_back(make_pair(0,0));

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]>>b[i]>>c[i];
		pandi.push_back(make_pair(c[i],i+1));
	}

	for (int i = 0; i < m; ++i)
	{
		cin>>u[i]>>v[i];
		uv[v[i]][u[i]]=1;
	}

	sort(pandi.begin() , pandi.end());
	
	int total = k+b[0];
	for (int i = 0; i < n-1; ++i)
	{
		extrasoldiers[i] = total-a[i+1];
		total = total+b[i+1];
	}
	extrasoldiers[n-1] = total;

	int mini = extrasoldiers[n-1];
	sparesoldiers[n-1] = mini;
	for (int i = n-2; i >= 0; --i)
	{
		mini = min(mini,extrasoldiers[i]);
		sparesoldiers[i] = mini;
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
			cout<<uv[i][j]<<" ";
		cout<<"\n";
	}

	for (int i = 0; i < n; ++i)
		cout<<sparesoldiers[i]<<" ";
	cout<<"   sparesoldiers \n";

	for (int i = pandi.size()-1; i >= 0; --i)
		cout<<pandi[i].first<<" "<<pandi[i].second<<"      ";
	cout<<"   pandi vector sorted \n";

	for (int i = 0; i < n; ++i)
	{
		if(extrasoldiers[i]<0)
		{
			cout<<"-1 \n";
			return 0;
		}
	}

	int sum = 0;
	for (int i = pandi.size()-1; i > 0; --i)
	{
		int t=0;
		for (int j = n; j > 0; --j)
		{
			if(uv[pandi[i].second][j]  and sparesoldiers[j-1]>0)
			{
				t=j;
				break;
			}
		}
		if(t>0)
		{
			int f=0;
			for (int i = t-1; i < n; ++i)
			{
				sparesoldiers[i]--;
				if(sparesoldiers[i]<0)
				{
					f=1;
					break;
				}
			}
			cout<<t<<"  t \n";
			for (int i = 0; i < n; ++i)
				cout<<sparesoldiers[i]<<" ";
			cout<<"   sparesoldiers \n";
			if(f) 
				break;
			sum = sum + pandi[i].first ; 
		}
	}


	for (int i = 0; i < n; ++i)
		cout<<extrasoldiers[i]<<" ";
	cout<<"   extrasoldiers \n";

	for (int i = 0; i < n; ++i)
		cout<<sparesoldiers[i]<<" ";
	cout<<"   sparesoldiers \n";

	cout<<sum<<"\n";

    return 0;
}