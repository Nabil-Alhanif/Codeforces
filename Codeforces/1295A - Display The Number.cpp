#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << string((n%2),'7') << string(((n/2)-(n%2)),'1') << '\n';
	}
}
