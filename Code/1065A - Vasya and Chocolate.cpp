#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		ll s,a,b,c;
		cin>>s>>a>>b>>c;
		ll ans=s/c;
		ans+=(ans/a)*b;
		cout<<ans<<"\n";
	}
}
