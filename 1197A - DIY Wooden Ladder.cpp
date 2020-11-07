#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
		ll ar[n];
		for (int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		sort(ar,ar+n);
		cout<<min(n-2,ar[n-2]-1)<<"\n";
	}
}
