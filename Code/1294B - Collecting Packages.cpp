#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		map<ll, vector<ll> > m;
		ll n;
		cin >> n;
		for (ll i = 0; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			m[a].push_back(b);
		}
		ll posx=0,posy=0;
		string s="";
		bool bisa = true;
		int i = 0;
		for (posx;;posx++) {
			if (m[posx].size()!=0) {
				sort(m[posx].begin(), m[posx].end());
				for (auto j : m[posx]) {
					i++;
					if (j<posy) {
						bisa=false;
						break;
					} else {
						for (posy; posy<j; posy++) {
							s+="U";
						}
					}
				}
			}
			if (!bisa)break;
			if (i==n)break;
			s+="R";
		}
		if (!bisa)cout << "NO\n";
		else {
			cout << "YES\n" << s << "\n";
		}
	}
}
