#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
	ull t;
	cin >> t;
	while (t--) {
		bool can = false;
		ull a, b, c, d;
		cin >> a >> b >> c >> d;
		ull i = d/c;
		if (i>a) {
			d-=(a*c);
		} else d-= (i*c);
		if (d<=b) cout << "YES\n";
		else cout << "NO\n";
	}
}
