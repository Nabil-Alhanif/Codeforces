#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll ans=0,a0,a1,a2,b0,b1,b2;
		cin>>a0>>a1>>a2>>b0>>b1>>b2;
		ll tmp;
		// Compare with a2
		tmp=min(a2,b1);
		ans+=tmp*2;
		a2-=tmp;
		b1-=tmp;
		//cout<<ans<<"\n";
		tmp=min(a2,b2);
		a2-=tmp;
		b2-=tmp;
		//cout<<ans<<"\n";
		tmp=min(a2,b0);
		a2-=tmp;
		b0-=tmp;
		//cout<<ans<<"\n";
		// Compare with a1
		tmp=min(a1,b1);
		a1-=tmp;
		b1-=tmp;
		//cout<<ans<<"\n";
		tmp=min(a1,b0);
		a1-=tmp;
		b0-=tmp;
		//cout<<ans<<"\n";
		tmp=min(a1,b2);
		ans-=tmp*2;
		cout<<ans<<"\n";
		//cout<<a0<<" "<<a1<<" "<<a2<<"\n";
		//cout<<b0<<" "<<b1<<" "<<b2<<"\n";
	}
}
