# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char bw[n];
	int b=0 , w=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>bw[i];
		if(bw[i]=='B')
			b++;
		else
			w++;
	}
	vector <int> v;
	if(b%2==0 and w%2!=0)
	{
		int i=0;
		while(i<n-1)
		{
			if(bw[i]=='B' and bw[i+1]=='B')
			{
				bw[i]='W';
				bw[i+1]='W';
				v.push_back(i+1);
				i=i+2;
			}
			else if(bw[i]=='B' and bw[i+1]=='W')
			{
				bw[i]='W';
				bw[i+1]='B';
				v.push_back(i+1);
				i=i+1;
			}
			else
				i=i+1;
		}
		cout<<v.size()<<"\n";
		for (int i = 0; i < v.size(); ++i)
			cout<<v[i]<<" ";
		cout<<"\n";
	}
	else if(w%2==0 and b%2!=0)
	{
		int i=0;
		while(i<n-1)
		{
			if(bw[i]=='W' and bw[i+1]=='W')
			{
				bw[i]='B';
				bw[i+1]='B';
				v.push_back(i+1);
				i=i+2;
			}
			else if(bw[i]=='W' and bw[i+1]=='B')
			{
				bw[i]='B';
				bw[i+1]='W';
				v.push_back(i+1);
				i=i+1;
			}
			else
				i=i+1;
		}
		cout<<v.size()<<"\n";
		for (int i = 0; i < v.size(); ++i)
			cout<<v[i]<<" ";
		cout<<"\n";
	}
	else if(w%2==0 and b%2==0)
	{
		int i=0;
		while(i<n-1)
		{
			if(bw[i]=='B' and bw[i+1]=='B')
			{
				bw[i]='W';
				bw[i+1]='W';
				v.push_back(i+1);
				i=i+2;
			}
			else if(bw[i]=='B' and bw[i+1]=='W')
			{
				bw[i]='W';
				bw[i+1]='B';
				v.push_back(i+1);
				i=i+1;
			}
			else
				i=i+1;
		}
		cout<<v.size()<<"\n";
		for (int i = 0; i < v.size(); ++i)
			cout<<v[i]<<" ";
		cout<<"\n";
	}			
	else
		cout<<"-1\n";	
    return 0;
}