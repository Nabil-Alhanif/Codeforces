#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll ans=0;
		ll n;
		scanf("%lld", &n);
		while (n>1) {
			if (n%2==0) {
				n/=2;
			} else if (n%3==0) {
				n/=3;
				n*=2;
			} else if (n%5==0) {
				n/=5;
				n*=4;
			} else {
				ans = -1;
				break;
			}
			ans++;
		}
		printf("%lld\n", ans);
	}
}
