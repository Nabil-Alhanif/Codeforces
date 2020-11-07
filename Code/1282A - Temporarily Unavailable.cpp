#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll a, b, n, r, off=0;
		scanf("%lld %lld %lld %lld", &a, &b, &n, &r);
		ll left = n-r;
		ll right = n+r;
		if (left>min(a, b)) {
			off+=min(left-min(a, b), max(a, b)-min(a, b)+1);
		}
		if (right<max(a, b)) {
			off+=min(max(a, b)-right, max(a, b)-min(a, b)+1);
		}
		off = min(off, max(a, b)-min(a, b));
		printf("%lld\n", off);
	}
}
