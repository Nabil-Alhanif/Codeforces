#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, ver=0, hor=0, a, b, mins=INT_MAX;
		bool udah=false;
		string s;
		cin >> n >> s;
		map<pair<ll, ll>, ll> m;
		m[{0,0}]=0;
		for (int i = 1; i <= n; i++) {
			if (s[i-1]=='U')ver++;
			else if (s[i-1]=='D')ver--;
			else if (s[i-1]=='R')hor++;
			else hor--;
			if (i-m[{hor,ver}]<mins&&(m[{hor,ver}]>0||hor==0&&ver==0)) {
				mins=i-m[{hor,ver}];
				a=i;
				b = m[{hor,ver}];
			}
			m[{hor,ver}]=i;
		}
		if (mins==INT_MAX)cout << "-1\n";
		else cout << b+1 << " " <<a  << "\n";
	}
}
