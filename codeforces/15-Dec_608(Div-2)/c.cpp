# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,sx,sy;
	cin>>n>>sx>>sy;
	int c[9];
	for (int i = 0; i < 9; ++i)
		c[i]=0;
	int x,y;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;

		if(x<sx)
		{
			if(y<sy)
			{
				c[7]++;
				c[8]++;
				c[6]++;
			}
			else if(y>sy)
			{
				c[1]++;
				c[8]++;
				c[2]++;
			}
			else
				c[8]++;
		}
		else if(x>sx)
		{
			if(y<sy)
			{
				c[4]++;
				c[5]++;
				c[6]++;
			}
			else if(y>sy)
			{
				c[4]++;
				c[2]++;
				c[3]++;
			}
			else
				c[4]++;
		}
		else
		{
			if(y<sy)
			{
				c[6]++;
			}
			else
				c[2]++;
		}
	}

	int mi=1 , ms=c[1];
	for (int i = 2; i < 9; ++i)
	{
		if(c[i]>ms)
		{
			mi=i;
			ms=c[i];
		}
	}

	

	cout<<c[mi]<<"\n";
	if(mi==1)
		cout<<sx-1<<" "<<sy+1<<"\n";
	else if(mi==2)
		cout<<sx<<" "<<sy+1<<"\n";
	else if(mi==3)
		cout<<sx+1<<" "<<sy+1<<"\n";
	else if(mi==4)
		cout<<sx+1<<" "<<sy<<"\n";
	else if(mi==5)
		cout<<sx+1<<" "<<sy-1<<"\n";
	else if(mi==6)
		cout<<sx<<" "<<sy-1<<"\n";
	else if(mi==7)
		cout<<sx-1<<" "<<sy-1<<"\n";
	else
		cout<<sx-1<<" "<<sy<<"\n";
    return 0;
}