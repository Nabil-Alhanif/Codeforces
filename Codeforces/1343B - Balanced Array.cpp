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
		ll n;
		cin>>n;
		n/=2;
		if ((n%2))
		{
			cout<<"NO\n";
			continue;
		}
		int fr[n],bc[n];
		int i=2,k=1;
		for (int j=0;j<n;j+=2)
		{
			fr[j]=i;
			fr[j+1]=i+2;
			i+=6;
			bc[j]=k;
			bc[j+1]=k+4;
			k+=6;
		}
		cout<<"YES\n";
		for (i=0;i<n;i++)cout<<fr[i]<<" ";
		for (i=0;i<n;i++)cout<<bc[i]<<" ";
		cout<<"\n";
	}
}
