#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k,ans=0;
		cin>>n>>k;
		ll a[n],b[n];
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			ans+=a[i];
		}
		for (int i=0;i<n;i++)cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for (int i=0;i<n&&i<k;i++)
		{
			ans+=max(0ll,b[n-i-1]-a[i]);
		}
		cout<<ans<<"\n";
	}
}
