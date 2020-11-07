#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	vector<ll> v;
	v.push_back(0);
	ll ar[n];
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
		if (i!=0)ar[i]+=ar[i-1];
	}
	if (ar[n-1]%3!=0||n<3) {
		cout << "0\n";
		return 0;
	} else {
		ll ans=0;
		ll tmp = ar[n-1]/3;
		ll temp=ar[n-1]/3*2;
		ll pos=n-2;
		for (ll i = n-3; i>=0;i--) {
			if (ar[i]==tmp) {
				ll an=0;
				for (ll j = pos; j > i; j--) {
					if (ar[j]==temp) {
						an++;
					}
				}
				pos=i;
				v.push_back(an+v[v.size()-1]);
			}
		}
		ans=0;
		for (auto i : v) {
			ans+=i;
		}
		cout << ans << "\n";
	}
}
