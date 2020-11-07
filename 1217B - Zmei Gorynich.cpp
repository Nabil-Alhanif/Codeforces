#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		ll m1=0,m2=0,s1=0,ans=0;
		while (n--) {
			ll damage, regen;
			cin >> damage >> regen;
			m1=max(m1,damage);
			if(damage-regen>s1) {
				s1=damage-regen;
				m2=damage;
			} else if(damage-regen==s1) {
				m2=max(m2,damage);
			}
		}
		if (m1>=x) {
			cout << 1 << "\n";
		} else if(s1>0){
			x-=m1;
			ans++;
			ans+=ceil((double)x/s1);
			cout << ans << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
}
