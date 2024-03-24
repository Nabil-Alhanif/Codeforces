#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
	ll q;
	cin>>q;
	while (q--) {
		ll n,b,mins=LLONG_MAX,maks=LLONG_MIN;
		cin>>n>>b;
		while (n--){
			ll price;
			cin>>price;
			mins=min(mins,price);
			maks=max(maks,price);
		}
		if (mins+b<maks-b) cout<<"-1\n";
		else cout<<mins+b<<"\n";
	}
}
