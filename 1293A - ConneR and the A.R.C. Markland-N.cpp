#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, s, k;
		cin >> n >> s >> k;
		map<int, int> m;
		for (int i = 0; i < k; i++) {
			ll tmp;
			cin >> tmp;
			m[tmp]=1;
		}
		for (int i = s, j=s; ; i++, j--) {
			if (i<=n&&m[i]==0) {
				cout << i-s << "\n";
				break;
			}
			if (j>0&&m[j]==0) {
				cout << s-j << "\n";
				break;
			}
		}
	}
}
