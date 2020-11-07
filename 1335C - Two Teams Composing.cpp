#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		map<ll,ll> m;
		ll n;
		cin>>n;
		ll ar[n],maks=0;
		for (ll i = 0; i < n; i++) {
			cin>>ar[i];
			m[ar[i]]++;
			//cout<<ar[i]<<" "<<m[ar[i]]<<" s\n";
			maks=max(m[ar[i]],maks);
		}
		if (n==1) {
			cout<<0<<"\n";
			continue;
		}
		n/=2;
		ll size=m.size();
		size--;
		if (size==maks) {
			cout<<size<<"\n";
		} else if (size<maks) {
			if (maks-size>1)cout<<size+1<<"\n";
			else cout<<size<<"\n";
		} else if (size>maks) {
			cout<<maks<<"\n";
		}
	}
}
