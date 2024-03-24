#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, ans=0;
		cin >> n;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll mins=ar[n-1];
		for (ll i = n-1; i >=0; i--) {
			if (ar[i]>mins)ans++;
			if (ar[i]<mins)mins=ar[i];
		}
		cout << ans <<"\n";
	}
}
