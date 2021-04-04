#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	if (n<m) {
		cout << "-1\n";
		return 0;
	}
	int tmp = ceil((double)n/2);
	for (int i = 1;;i++) {
		if (m*i>=tmp&&m*i<=n) {
			cout << m*i << "\n";
			break;
		}
		if (m*i>n) {
			cout << "-1\n";
			break;
		}
	}
}
