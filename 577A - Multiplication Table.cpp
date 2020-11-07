#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans=0, n, x;
	cin >> n >> x;
	for (int i = 1; i <= n&&i<=x; i++) {
		if (x%i==0&&x/i<=n)ans++;
	}
	cout << ans << "\n";
}
