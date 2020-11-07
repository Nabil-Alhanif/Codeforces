#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k;
		cin>>n>>k;
		ll ans = (k/(n-1))*n+(k%(n-1));
		if (!(k%(n-1)))
			ans--;
		cout<<ans<<"\n";
	}
}
