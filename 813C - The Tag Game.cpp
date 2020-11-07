#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool aVis[200005];
bool bVis[200005];
ll aDist[200005];
ll bDist[200005];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	map<ll, vector<ll> > tree;
	ll n,x,ans=0;
	cin>>n>>x;
	aVis[1]=1;
	bVis[x]=1;
	for (int i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	queue<pair<ll,ll> > q;
	q.push({1,0});
	while (!q.empty())
	{
		ll curPos=q.front().first, curDist=q.front().second;
		q.pop();
		for (auto i:tree[curPos])
		{
			if (!aVis[i])
			{
				aVis[i]=1;
				aDist[i]=curDist+1;
				q.push({i,curDist+1});
			}
		}
	}
	/*
	for (int i=1;i<=n;i++)
	{
		cout<<aDist[i]<<" ";
	}cout<<"\n";
	*/
	q.push({x,0});
	while (!q.empty())
	{
		ll curPos=q.front().first, curDist=q.front().second;
		q.pop();
		for (auto i:tree[curPos])
		{
			if (!bVis[i])
			{
				bVis[i]=1;
				bDist[i]=curDist+1;
				q.push({i,curDist+1});
			}
		}
	}
	/*
	for (int i=1;i<=n;i++)
	{
		cout<<bDist[i]<<" ";
	}cout<<"\n";
	*/
	for (int i=1;i<=n;i++)
	{
		if (aDist[i]!=bDist[i]&&aDist[i]>bDist[i])
		{
			if (aDist[i]>=ans)
				ans=aDist[i];
		}
	}
	cout<<ans*2<<"\n";
}
