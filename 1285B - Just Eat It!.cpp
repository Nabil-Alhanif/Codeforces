#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<class t> t kadaneAlgo(t *p, t size) {
	t maxEnd=0, maxPoint=0;
	for (t i = 0; i < size; i++) {
		maxEnd+=*p;
		if (maxEnd<0) {
			maxEnd=0;
		}
		maxPoint=max(maxPoint, maxEnd);
		p++;
	}
	return maxPoint;
}

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, y=0, a=0;
		cin >> n;
		ll ar[n];
		for (ll i = 0; i < n; i++) {
			cin >> ar[i];
			y+=ar[i];
		}
		ll *p=ar;
		n-=1;
		a=kadaneAlgo(p, n);
		p=&ar[1];
		ll b = kadaneAlgo(p, n);
		a = max(a, b);
		if (a>=y) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
