#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, d, ans=0;;
		cin >> n >> d;
		for (ll i = 0; i < n; i++) {
			ll tmp;
			cin >> tmp;
			if (i*tmp<=d) {
				ans+=tmp;
				d-=(i*tmp);
			} else {
				ans+=d/i;
				d=0;
			}
		}
		cout << ans <<"\n";
	}
}
