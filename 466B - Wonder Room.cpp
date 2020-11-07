#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, a, b,ans1,ans2;
	cin >> n >> a >> b;
	ll sum = 6*n, maks=LLONG_MAX;
	if (a*b>=sum) {
		cout << a*b << "\n";
		cout <<a  << " " << b << "\n";
		return 0;
	}
	for (ll i = 1; i*i<=sum; i++) {
		ll k = ceil((double)sum/i);
		ll hasil = k*i;
		if (hasil<maks) {
			if (i>=a&&k>=b) {
				maks = hasil;
				ans1=i;
				ans2=k;
			} else if (i>=b&&k>=a) {
				maks = hasil;
				ans1=k;
				ans2=i;
			}
		}
	}
	cout << maks << '\n';
	cout << ans1 << " " << ans2 << '\n';
}
