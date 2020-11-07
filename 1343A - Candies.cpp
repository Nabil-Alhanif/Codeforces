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
		ll n;
		cin>>n;
		int j=1;
		for (ll i=2;j<=n;i*=2)
		{
			j+=i;
			if (!(n%j))
			{
				cout<<n/j<<"\n";
				break;
			}
		}
	}
}
