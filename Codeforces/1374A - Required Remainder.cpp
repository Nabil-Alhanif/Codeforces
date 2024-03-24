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
		ll x,y,n,m;
		cin>>x>>y>>n;
		m=(n/x)*x+y;
		cout<<(m>n?m-((m-n)+x-((m-n)%x)):m)<<"\n";
	}
}
