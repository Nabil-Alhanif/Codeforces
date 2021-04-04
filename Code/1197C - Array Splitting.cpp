#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k,ans=0;
	cin>>n>>k;
	vector<ll>v(n),dif(n-1);
	for (int i=0;i<n;i++)
		cin>>v[i];
	for (int i=1;i<n;i++)
	{
		dif[i-1]=v[i]-v[i-1];
		ans+=dif[i-1];
	}
	sort(dif.begin(),dif.end());
	for (int i=1;i<k;i++)
		ans-=dif[n-i-1];
	cout<<ans<<"\n";
}
