#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,ans=0;
		map<ll,ll> m;
		cin>>n;
		vector<ll> v(n+1);
		for (int i=1;i<=n;i++)
		{
			cin>>v[i];
			m[v[i]]++;
			v[i]+=v[i-1];
		}
		for (auto i:m)
		{
			//cout<<i.first<<" "<<i.second<<" mm\n";
			for(int l=0,r=2;l<r-1&&r<=n;r++)
			{
				while (v[r]-v[l]>i.first&&l<r-2)
				{
					l++;
				}
				if (v[r]-v[l]==i.first)
				{
					//cout<<r<<" "<<l<<" "<<i.first<<" aaa\n";
					ans+=i.second;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
