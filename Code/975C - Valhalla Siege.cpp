#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,q,totStrength=0;
	cin>>n>>q;
	ll strength[n+1];
	strength[0]=0;
	for (int i=n;i>0;i--)
		cin>>strength[i];
	for (int i=1;i<=n;i++)
		strength[i]+=strength[i-1];
	totStrength=strength[n];
	ll locStrength=totStrength;
	while (q--)
	{
		ll arrow;
		cin>>arrow;
		//cout<<arrow;
		locStrength=max(0ll,locStrength-arrow);
		ll l=0,r=n,mid,ans=0;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (strength[mid]==locStrength)
			{
				ans=mid;
				break;
			}
			if (strength[mid]<locStrength)
				l=mid+1;
			if (strength[mid]>locStrength)
			{
				ans=mid;
				r=mid-1;
			}
		}
		if (ans==0)ans=n;
		if (locStrength<=0)
			locStrength=totStrength;
		cout<<ans<<"\n";
	}
}
