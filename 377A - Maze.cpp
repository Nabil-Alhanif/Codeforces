#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
pair<ll,ll>pos={0,0};
char ar[500][500];
bool vis[500][500];
void dfs(ll x, ll y)
{
	if (x+1<n)
	{
		if (!vis[x+1][y]&&ar[x+1][y]=='.')
		{
			vis[x+1][y]=1;
			dfs(x+1,y);
		}
	}
	if (x-1>=0)
	{
		if (!vis[x-1][y]&&ar[x-1][y]=='.')
		{
			vis[x-1][y]=1;
			dfs(x-1,y);
		}
	}
	if (y+1<m)
	{
		if (!vis[x][y+1]&&ar[x][y+1]=='.')
		{
			vis[x][y+1]=1;
			dfs(x,y+1);
		}
	}
	if (y-1>=0)
	{
		if (!vis[x][y-1]&&ar[x][y-1]=='.')
		{
			vis[x][y-1]=1;
			dfs(x,y-1);
		}
	}
	if (k>0)
	{
		ar[x][y]='X';
		//cout<<x<<" "<<y<<"\n";
		k--;
	}
}
int main()
{
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>ar[i][j];
			if (ar[i][j]=='.')pos={i,j};
		}
	}
	dfs(pos.first,pos.second);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cout<<ar[i][j];
		}cout<<"\n";
	}
}
