#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll ar1[a], ar2[b];
	for (ll i = 0; i < a; i++) {
		scanf("%lld", &ar1[i]);
	}
	for (ll i = 0; i < b; i++) {
		scanf("%lld", &ar2[i]);
	}
	sort(ar1, ar1+a);
	for (ll i = 0; i < b; i++) {
		ll tmp = lower_bound(ar1, ar1+a, ar2[i]+1)-ar1;
		printf("%lld ", tmp);
	}printf("\n");
}
