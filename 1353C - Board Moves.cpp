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
		ll n,ans=0,tmp=2;
		cin>>n;
		for (int i=1;i*2<=n;i++)
		{
			ans+=i*tmp*4;
			tmp+=2;
		}
		cout<<ans<<"\n";
	}
}
