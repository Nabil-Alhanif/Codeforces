#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll tc[n],ts[k];
	for (int i=0;i<n;i++)cin>>tc[i];
	for (int i=0;i<k;i++)cin>>ts[i];
	sort(tc,tc+n);
	vector<vector<ll> > v;
	vector<ll> v2;
	ll last=ts[0],c=0,t=0;
	for(int i=0;i<n;i++)
	{
		if (c==last)
		{
			v.push_back(v2);
			v2.clear();
			last=ts[0];c=0;t=0;
		}
		ll tmp=last-c;
		if (ts[tc[i]-1]<tmp)
		{
			last=ts[tc[i]-1];
			c=0;
		}
		v2.push_back(tc[i]);
		c++;
		//cout<<last<<" "<<c<<" tc\n";
		if (i==n-1)
		{
			v.push_back(v2);
			break;
		}
	}
	cout<<v.size()<<"\n";
	for (auto i:v)
	{
		cout<<i.size();
		for (auto j:i)cout<<" "<<j;
		cout<<"\n";
	}
}
