#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a,b,ans=0;
	cin>>n>>a>>b;
	pair<pair<ll,ll>,ll> seal[n];
	for (int i=0;i<n;i++)
	{
		cin>>seal[i].first.first>>seal[i].first.second;
		seal[i].second=seal[i].first.first*seal[i].first.second;
	}
	for (int i=0;i<n;i++)
	{
		bool b1=(seal[i].first.first<=a&&seal[i].first.second<=b);
		bool b2=(seal[i].first.first<=b&&seal[i].first.second<=a);
		if(b1||b2)
		{
			for (int j=i+1;j<n;j++)
			{
				//cout<<i<<" "<<j<<"\n";
				if (b1)
				{
					if (seal[j].first.first<=a&&seal[j].first.second<=b)
					{
						if (seal[j].first.first+seal[i].first.first<=a||seal[j].first.second+seal[i].first.second<=b)
							ans=max(ans,seal[i].second+seal[j].second);
					}
					if (seal[j].first.first<=b&&seal[j].first.second<=a)
					{
						if (seal[j].first.second+seal[i].first.first<=a||seal[j].first.first+seal[i].first.second<=b)
							ans=max(ans,seal[i].second+seal[j].second);
					}
				}
				if (b2)
				{
					if (seal[j].first.first<=a&&seal[j].first.second<=b)
					{
						if (seal[j].first.first+seal[i].first.second<=a||seal[j].first.second+seal[i].first.first<=b)
							ans=max(ans,seal[i].second+seal[j].second);
					}
					if (seal[j].first.first<=b&&seal[j].first.second<=a)
					{
						if (seal[j].first.first+seal[i].first.first<=b||seal[j].first.second+seal[i].first.second<=a)
							ans=max(ans,seal[i].second+seal[j].second);
					}
				}
			}	
		}
	}
	cout<<ans<<"\n";
}
