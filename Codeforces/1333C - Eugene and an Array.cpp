#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,ans=0,pos=0,tot=0;
	cin>>n;
	map<ll,ll>m;
	m[0]=1;
	for (int i = 1; i <= n; i++) {
		ll tmp;
		cin>>tmp;
		tot+=tmp;
		pos=max(pos,m[tot]);
		ans+=i-pos;
		m[tot]=i+1;
	}
	cout<<ans<<"\n";
}
