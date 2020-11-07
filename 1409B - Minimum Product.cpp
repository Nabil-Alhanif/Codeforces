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
		ll a,b,x,y,n,ans;
		cin>>a>>b>>x>>y>>n;
		ll ca=max(a-n,x);
		ll cb=max(b-(n-(a-ca)),y);
		ans=ca*cb;
		cb=max(b-n,y);
		ca=max(a-(n-(b-cb)),x);
		ans=min(ans,cb*ca);
		cout<<ans<<"\n";
	}
}
