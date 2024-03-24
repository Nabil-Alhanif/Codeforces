#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	ll ar[n+1], tm[n+1];
	map<ll, ll> ma;
	memset(ar,0, sizeof(ar));
	for (ll i = 1; i <= n; i++) {
		ll tmp;
		cin >> tmp;
		tm[i]=tmp;
	}
	ar[n]=1;
	ma[tm[n]]++;
	for (ll i = n-1; i > 0; i--) {
		ma[tm[i]]++;
		if (ma[tm[i]]==1)ar[i]++;
		ar[i]+=ar[i+1];
	}
	while (m--) {
		ll pos;
		cin >> pos;
		cout<<ar[pos]<<"\n";
	}
}
