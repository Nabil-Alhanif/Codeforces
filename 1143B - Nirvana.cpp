#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(ll n)
{
	if (n<10) return max(n,1ll);
	return max(n%10*count(n/10),9*count((n/10)-1));
}

int main()
{
	ll n,l,ans=1;
	cin>>n;
	ans=count(n);
	cout<<ans<<"\n";
}
