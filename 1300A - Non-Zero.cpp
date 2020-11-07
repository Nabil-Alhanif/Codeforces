#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, tot=0, z=0;
		cin >> n;
		while (n--) {
			ll tmp;
			cin >> tmp;
			if (tmp==0)z++;
			tot+=tmp;
		}
		if (tot+z==0)z++;
		cout << z << "\n";
	}
}
