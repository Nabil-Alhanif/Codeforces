#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll ans=0,n;
	cin>>n;
	ll ar[n];
	for (int i=0;i<n;i++)cin>>ar[i];
	sort(ar,ar+n);
	for (int i=0;i<n;i++)
	{
		if (i==n-1)ans+=ar[i]*(n);
		else ans+=ar[i]*(i+2);
	}
	cout<<ans<<"\n";
}
