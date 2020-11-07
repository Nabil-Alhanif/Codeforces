#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,ans=LLONG_MAX;
	cin>>n;
	ll l=1,r=n,mid,half=n/2+n%2;
	while (l<=r)
	{
		mid=(l+r)/2;
		ll tmp=n,locTot=0;
		while (tmp>=mid)
		{
			tmp-=mid;
			locTot+=mid;
			tmp-=(tmp/10);
		}
		locTot+=tmp;
		if (locTot>=half)
		{
			ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<"\n";
}
