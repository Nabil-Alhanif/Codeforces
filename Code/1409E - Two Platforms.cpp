#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k,ans=0;
		cin>>n>>k;
		ll ar[n];
		for (int i=0;i<n;i++)
			cin>>ar[i];
		for (int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
		}
		sort(ar,ar+n);
		ll l[n],r[n];
		ll j=0;
		for (ll i=0;i<n;i++)
		{
			while (ar[i]-ar[j]>k)j++;
			l[i]=i-j+1;
			if (i)
				l[i]=max(l[i],l[i-1]);
		}
		j=n-1;
		for (ll i=n-1;i>=0;i--)
		{
			while (ar[j]-ar[i]>k)j--;
			r[i]=j-i+1;
			if (i!=n-1)
				r[i]=max(r[i],r[i+1]);
		}
		for (int i=0;i<n-1;i++)
			ans=max(r[i+1]+l[i],ans);
		ans=max(ans,l[n-1]);
		cout<<ans<<"\n";
	}
}
