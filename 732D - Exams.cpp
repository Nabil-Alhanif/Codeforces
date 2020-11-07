#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,tot=0;
	cin>>n>>m;
	pair<ll,vector<ll> > ar[m+1];
	ll day[n+1];
	day[0]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>day[i];
		ar[day[i]].second.push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>ar[i].first;
		tot+=ar[i].first+1;
		ar[i].second.push_back(1000000);
	}
	if (tot>n)
		return cout<<"-1\n",0;
	ll maksDay=0;
	for (int i=1;i<=m;i++)
	{
		for (auto j:ar[i].second)
		{
			if (j>=ar[i].first+1)
			{
				maksDay=max(j,maksDay);
				break;
			}
		}
	}
	if (maksDay>n)
		return cout<<"-1\n",0;
	for (int i=max(maksDay,tot);i<=n;i++)
	{
		if (day[i]!=0)
		return cout<<i<<"\n",0;
	}
}
