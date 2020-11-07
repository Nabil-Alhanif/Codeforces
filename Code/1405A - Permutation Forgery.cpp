#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
		ll ar[n];
		for (int i=0;i<n;i++)
			cin>>ar[i];
		for (int i=n-1;i>=0;i--)
			cout<<ar[i]<<" ";
		cout<<"\n";
	}
}
