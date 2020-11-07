#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int a, b, c, ans;
	cin >> a >> b >> c;
	ans = max(a+b+c, max(a+b*c, max(a*b+c, max((a+b)*c, max(a*(b+c), a*b*c)))));
	cout << ans << "\n";
}
