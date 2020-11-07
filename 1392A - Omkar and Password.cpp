#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,f=0,ans;
		cin>>n;
		ans=n;
		while (n--)
		{
			ll tmp;
			cin>>tmp;
			if (!f)f=tmp;
			else if (tmp!=f)ans=1;
		}
		cout<<ans<<"\n";
	}
}
