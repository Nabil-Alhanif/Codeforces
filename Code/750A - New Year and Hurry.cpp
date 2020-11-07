#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, total = 0;
	cin >> n >> m;
	m = 240 - m;
	for (int i = 1; i <= n; i++) {
		total += i*5;
		if (total > m) {
			cout << i - 1 << endl;
			break;
		} 
		if (total <= m && i == n) {
			cout << i << endl;
			break;
		}
	}
}
