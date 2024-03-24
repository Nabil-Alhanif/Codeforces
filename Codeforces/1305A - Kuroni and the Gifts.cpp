#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin>>n;
		ll x[n],y[n];
		for (int i = 0; i < n; i++) {
			cin>>x[i];
		}
		for (int i = 0; i < n; i++) {
			cin>>y[i];
		}
		sort(x, x+n);
		sort(y, y+n);
		for (int i = 0; i < n; i++) {
			cout<<x[i]<<" ";
		}
		cout<<"\n";
		for (int i = 0; i < n; i++) {
			cout << y[i]<<" ";
		}
		cout<<"\n";
	}
}
