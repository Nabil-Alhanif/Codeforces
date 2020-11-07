#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,tot=0,p=0;
		cin>>n;
		ll ar[n+1];
		ar[0]=0;
		for (ll i=1;i<=n;i++)
			cin>>ar[i];
		for (ll i=n;i>0;i--)
		{
			if (ar[i]<0)
			{
				tot-=ar[i];
				continue;
			}
			if (ar[i]>=tot)
			{
				ar[i]-=tot;
				tot=0;
				p+=ar[i];
			}
			else
				tot-=ar[i];
		}
		cout<<p<<"\n";
	}
}
