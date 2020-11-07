#include <bits/stdc++.h>
using namespace std;

map<int, int> m, m2;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int t, a, b;
		cin >> t >> a >> b;
		m[t]+=a;
		m2[t]+=a+b;
	}
	if (m[1]>=m2[1]/2)cout << "LIVE\n";
	else cout << "DEAD\n";
	if (m[2]>=m2[2]/2) cout << "LIVE\n";
	else cout << "DEAD\n";
}
