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
		ll n,k;
		cin>>n>>k;
		ll ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		for (int i=0;i<n/2;i++)
		{
			cout<<"asd "<<ar[i]<<" "<<ar[n-i-1]<<" "<<ar[i]+ar[n-i-1]<<" ";
		}cout<<"\n";
	}
}
