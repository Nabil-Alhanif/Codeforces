#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ar[3][10000005];
int main() {
	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll c, d;
		cin >> c >> d;
		ar[c][d]=!ar[c][d];
		queue<pair<ll, ll> > s;
		bool path=false;
		s.push(make_pair(1, 1));
		while (!s.empty()) {
			ll x, y;
			x = s.front().first;
			y = s.front().second;
			if (x==2&&y==n) {
				path=true;
				cout << "Yes\n";
				break;
			}
			s.pop();
			if (x<2&&!ar[x+1][y]) {
				s.push({x+1, y});
			}
			if (!ar[x][y+1]) {
				s.push({x, y+1});
			}
		}
		if (!path)cout << "No\n";
	}
}
