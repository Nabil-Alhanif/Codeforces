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
		ll a,b,q,ar[100005];
		cin>>a>>b>>q;
		ll tmp=a*b/__gcd(a,b);
		ar[0]=0;
		for (ll i=0;i<tmp;i++)
		{
			ar[i+1]=ar[i];
			if (i%a%b!=i%b%a)ar[i+1]++;
		}
		while (q--)
		{
			ll l,r;
			cin>>l>>r;
			r++;
			ll ans=(r/tmp-l/tmp)*ar[tmp]+ar[r%tmp]-ar[l%tmp];
			cout<<ans<<" ";
		}cout<<"\n";
	}
}
