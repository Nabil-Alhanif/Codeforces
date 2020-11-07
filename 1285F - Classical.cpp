#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll __lcm(ll a,ll b) {
	return a*b/__gcd(a,b);
}
int main() {
	ll n;
	cin >> n;
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ll t1=v[n-1],t2=v[n-2],t3=1,t4=1,t5=1,ans=0;
	if (n>2)t3=v[n-3];
	if(n>3)t4=v[n-4];
	for (int i = 0; i < n; i++) {
		ll tmp=v[i];
		if (tmp%2!=t1%2)t5=max(t5,tmp);
	}
	for (ll i = 0; i < n; i++) {
		ans=max(ans,__lcm(t1,v[i]));
	}
	for (int i = 0; i < n; i++) {
		ans=max(ans,__lcm(t2,v[i]));
	}
	for (int i = 0; i < n; i++) {
		ans=max(ans,__lcm(t3,v[i]));
	}
	for (int i = 0; i < n; i++) {
		ans=max(ans,__lcm(t4,v[i]));
	}
	for (int i = 0; i < n; i++) {
		ans=max(ans,__lcm(t5,v[i]));
	}
	cout << ans << "\n";
}
