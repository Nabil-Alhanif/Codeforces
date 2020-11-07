#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll n, p, k;
		scanf("%lld %lld %lld", &n,&p, &k);
		ll things[n];
		for (ll i = 0; i < n; i++) {
			scanf("%lld", &things[i]);
		}
		sort(things, things+n);
		ll tmp = lower_bound(things, things+n, p)-things;
		printf("%lld\n", tmp);
	}
}
