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
		ll n,pa=0,pb=0;
		cin>>n;
		ll ar[n];
		for (int i=0;i<n;i++)
		{
			cin>>ar[i];
			if (i%2!=ar[i]%2)
			{
				if(i%2)pb++;
				else pa++;
			}
		}
		cout<<(pa==pb?pa:-1)<<"\n";
	}
}
