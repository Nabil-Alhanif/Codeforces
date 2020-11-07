#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b,n;
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		ll c=max(a,b),d=min(a,b),ans=0;
		ll dif=c/d;
		if (dif*d!=c)
		{
			cout<<"-1\n";
			continue;
		}
		//cout<<c<<" "<<d<<" "<<dif<<"\n";
		while (dif%8==0)
		{
			if (c==d)break;
			dif/=8;
			ans++;
		}
		while (dif%4==0)
		{
			if (c==d)break;
			dif/=4;
			ans++;
		}
		while (dif%2==0)
		{
			if (c==d)break;
			dif/=2;
			ans++;
		}
		if (dif!=1)ans=-1;
		cout<<ans<<"\n";
	}
}
