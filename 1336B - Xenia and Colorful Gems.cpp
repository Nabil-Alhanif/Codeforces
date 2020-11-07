#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		ll ans=ULLONG_MAX;
		ll aa,bb,cc;
		cin>>aa>>bb>>cc;
		vector<ll> a(aa),b(bb),c(cc);
		for (int i=0;i<aa;i++)cin>>a[i];
		for (int i=0;i<bb;i++)cin>>b[i];
		for (int i=0;i<cc;i++)cin>>c[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		for (auto i:a)
		{
			auto j=lower_bound(b.begin(),b.end(),i);
			auto k=upper_bound(c.begin(),c.end(),i);
			if (j==b.end()||k==c.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		for (auto i:c)
		{
			auto j=lower_bound(a.begin(),a.end(),i);
			auto k=upper_bound(b.begin(),b.end(),i);
			if (j==a.end()||k==b.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		for (auto i:b)
		{
			auto j=lower_bound(c.begin(),c.end(),i);
			auto k=upper_bound(a.begin(),a.end(),i);
			if (j==c.end()||k==a.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		for (auto i:a)
		{
			auto j=lower_bound(c.begin(),c.end(),i);
			auto k=upper_bound(b.begin(),b.end(),i);
			if (j==c.end()||k==b.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		for (auto i:c)
		{
			auto j=lower_bound(b.begin(),b.end(),i);
			auto k=upper_bound(a.begin(),a.end(),i);
			if (j==b.end()||k==a.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		for (auto i:b)
		{
			auto j=lower_bound(a.begin(),a.end(),i);
			auto k=upper_bound(c.begin(),c.end(),i);
			if (j==a.end()||k==c.begin())continue;
			k--;
			ll tmp=((i-*j)*(i-*j))+((*j-*k)*(*j-*k))+((*k-i)*(*k-i));
			ans=min(ans,tmp);
		}
		cout<<ans<<"\n";
	}
}
