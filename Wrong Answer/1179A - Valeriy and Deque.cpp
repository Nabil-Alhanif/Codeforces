#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	deque<ll> d;
	ll n,q;
	cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		d.push_back(tmp);
	}
	ll i = 1;
	while (q--) {
		ll temp;
		cin >> temp;
		ll a, b;
		while (i<temp) {
			a = d.front();
			d.pop_front();
			b = d.front();
			d.pop_front();
			if (a>b) {
				d.push_front(a);
				d.push_back(b);
			} else {
				d.push_front(b);
				d.push_back(a);
			}
			i++;
		}
		a = d.front();
		d.pop_front();
		b = d.front();
		d.pop_front();
		if (a>b) {
			d.push_front(a);
			d.push_back(b);
		} else {
			d.push_front(b);
			d.push_back(a);
		}
		i++;
		cout << a << " " << b << "\n";
	}
}
