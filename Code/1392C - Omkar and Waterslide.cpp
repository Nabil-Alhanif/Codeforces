#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,ans=0;
		cin>>n;
		ll ar[n];
		for (int i=0;i<n;i++)
		{
			cin>>ar[i];
			if (i!=0)
			{
				if (ar[i]<ar[i-1])
					ans+=ar[i-1]-ar[i];
			}
		}
		cout<<ans<<"\n";
	}
}
