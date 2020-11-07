#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll times[2000000], ans=0;
int main() {
	ll j=0;
	times[0]=0;
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &times[i]);
		times[i]+=times[i-1];
		while (j<i) {
			if (times[i]-times[j]<=m) {
				ans=max(ans, i-j);
				break;
			}
			j++;
		}
	}
	printf("%lld\n", ans);
}
