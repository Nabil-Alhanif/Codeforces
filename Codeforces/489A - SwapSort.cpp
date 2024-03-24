#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll ar[n],ar2[n];
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
		ar2[i]=ar[i];
	}
	ll ans=0;
	vector<pair<ll, ll> > v;
	sort(ar2, ar2+n);
	for (int i = 0; i < n; i++) {
		if (ar[i]!=ar2[i]) {
			for (int j = i+1; j < n; j++) {
				if (ar[j]==ar2[i]) {
					ar[i]+=ar[j];
					ar[j]=ar[i]-ar[j];
					ar[i]-=ar[j];
					ans++;
					v.push_back(make_pair(i,j));
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	for (ll i = 0; i < ans; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}
