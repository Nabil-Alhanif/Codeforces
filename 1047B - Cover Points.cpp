#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,ans=0;
	cin>>n;
	while (n--)
	{
		ll a,b;
		cin>>a>>b;
		ans=max(ans,(a+b));
	}
	cout<<ans<<"\n";
}
