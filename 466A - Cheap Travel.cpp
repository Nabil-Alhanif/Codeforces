#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b, ans=0;
	cin >> n >> m >> a >> b;
	if (m!=1) {
		ans=(n/m)*b;
		ans+=min(b, a*(n%m));
	}else {
		ans=min(a, b)*n;
	}
	ans = min(ans, a*n);
	cout << ans << "\n";
}
