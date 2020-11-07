#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	//vector<vector<bool> > board(n,vector<bool>(m));
	cout<<x<<" "<<y<<"\n";
	for (int i=x-1;i>0;i--)
	{
		cout<<i<<" "<<y<<"\n";
	}
	for (int i=x+1;i<=n;i++)
	{
		cout<<i<<" "<<y<<"\n";
	}
	for (int i=y+1;i<=m;i++)
	{
		if (y%2!=i%2)
		{
			for (int j=n;j>0;j--)
			{
				cout<<j<<" "<<i<<"\n";
			}
		}
		else
		{
			for (int j=1;j<=n;j++)
			{
				cout<<j<<" "<<i<<"\n";
			}
		}
	}
	for (int i=y-1;i>0;i--)
	{
		if (m%2!=i%2)
		{
			for (int j=n;j>0;j--)
			{
				cout<<j<<" "<<i<<"\n";
			}
		}
		else
		{
			for (int j=1;j<=n;j++)
			{
				cout<<j<<" "<<i<<"\n";
			}
		}
	}
}
