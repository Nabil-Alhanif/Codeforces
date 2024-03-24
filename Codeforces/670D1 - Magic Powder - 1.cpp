#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k,ans=INT_MAX,tot=0;
	cin>>n>>k;
	ll a[n],b[n];
	for (ll i=0;i<n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	for (ll i=0;i<n;i++)
	{
		cin>>b[i];
		ans=min(ans,b[i]/a[i]);
	}
	for (ll i=0;i<n;i++)
	{
		b[i]-=ans*a[i];
	}
	ll l=1,r=1000,pos=0;
	while (l<=r)
	{
		ll mid=(l+r)/2,tmp=0;
		for (int i=0;i<n;i++)
		{
			tmp+=min(b[i],mid*a[i]);
		}
		ll tm=tot*mid;
		if (tm==tmp+k)
		{
			pos=mid;
			break;
		} else if (tm>tmp+k)
		{
			r=mid-1;
		} else {
			pos=mid;
			l=mid+1;
		}
	}
	cout<<ans+pos<<"\n";
}
