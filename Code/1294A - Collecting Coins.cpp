#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int ar[3], d;
		cin >> ar[0] >> ar[1] >> ar[2] >> d;
		sort(ar, ar+3);
		d-=((abs(ar[2]-ar[1])+(abs(ar[2]-ar[0]))));
		if (d%3==0&&d>=0)cout << "YES\n";
		else cout << "NO\n";
	}
}
