#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sec(const pair<ll,ll>&l, const pair<ll,ll>&r)
{
	return (l.second<r.second);
}
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k;
		cin>>n>>k;
		k--;
		pair<ll,ll> ar[n];
		for (int i=1;i<=n;i++)
		{
			cin>>ar[i-1].first;
			ar[i-1].second=i;
		}
		sort(ar,ar+n);
		/*
		for (int i=0;i<n;i++)
			cout<<ar[i].first<<"->"<<ar[i].second<<" ";
		cout<<"\n";
		*/
		for (int i=0;i<n;i++)
			ar[i].first=ar[n-1].first-ar[i].first;
		if (k%2)
		{
			for (int i=n-1;i>=0;i--)
				ar[i].first=ar[0].first-ar[i].first;
		}
		sort(ar,ar+n,sec);
		for (int i=0;i<n;i++)
			cout<<ar[i].first<<" ";
		cout<<"\n";
	}
}
