#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll com(ll a) {
	return max((ll)0, a*(a-1)/2);
}
int main()  {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	map<ll, ll> m;
	ll n, maks=INT_MIN, mins=INT_MAX, ans=0;
	cin >> n;
	ll beau[n];
	for (ll i = 0; i < n; i++) {
		cin >> beau[i];
		maks=max(maks, beau[i]);
		mins=min(mins, beau[i]);
		m[beau[i]]++;
	}
	ll dif = maks-mins;
	sort(beau, beau+n);
	if(dif!=0) {
		for(int i = 0; i < n; i++) {
			ans+=m[beau[i]+dif];
		}
	} else {
		ans=com(n);
	}
	cout << dif <<" "<<ans<<"\n";
}
