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
		bool can=false;
		for (ll i = 2; i*i<=n; i++) {
			if (n%i==0) {
				ll j = n/i;
				for (ll k = 2; k*k<=j; k++) {
					if (j%k==0&&k!=i) {
						if (j/k>=2&&j/k!=i&&j/k!=k) {
							cout<<"YES\n"<<i<<" "<<k<<" "<<j/k<<"\n";
							can=true;
							break;
						}
					}
				}if (can)break;
			}
		}if(can)continue;
		cout << "NO\n";
	}
}
