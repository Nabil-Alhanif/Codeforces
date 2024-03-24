#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		ll tmp = r/l;
		tmp*=l;
		printf("%lld %lld\n", l, tmp);
	}
}
