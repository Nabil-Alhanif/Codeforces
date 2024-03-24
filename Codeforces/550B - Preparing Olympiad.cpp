#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,l,r,x,ans=0;
	cin>>n>>l>>r>>x;
	ll ar[n];
	for (int i=0;i<n;i++)cin>>ar[i];
	sort(ar,ar+n);
	queue<pair<pair<ll,ll>,pair<ll,ll> > >q;
	for (int i=0;i<n-1;i++)
	{
		q.push({{i,i},{ar[i],1}});
	}
	while (!q.empty())
	{
		ll start,cur,tot,way;
		start=q.front().first.first;
		cur=q.front().first.second;
		tot=q.front().second.first;
		way=q.front().second.second;
		//cout<<start<<" "<<cur<<" "<<tot<<" "<<way;
		q.pop();
		if (tot>r)
		{
			//cout<<"\n";
			continue;
		}
		if (way>1&&tot>=l&&tot<=r&&ar[cur]-ar[start]>=x)
		{
			ans++;
			//cout<<" True";
		}
		for (int i=cur+1;i<n;i++)
		{
			q.push({{start,i},{tot+ar[i],way+1}});
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
}
