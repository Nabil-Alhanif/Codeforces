#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	map<ll,bool>ma;
	while (n--) {
		ll c;
		cin>>c;
		while (c--) {
			ll bulb;
			cin>>bulb;
			ma[bulb]=1;
		}
	}
	cout<<(ma.size()==m?"YES\n":"NO\n");
}
