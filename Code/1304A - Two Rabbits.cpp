#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		ll ans = ((abs(y-x)/(a+b))*(a+b)==abs(y-x)?(abs(y-x)/(a+b)):-1);
		cout << ans <<"\n";
	}
}
