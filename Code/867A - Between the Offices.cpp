#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s = 0, f = 0;
	cin >> n;
	string ss;
	cin >> ss;
	for (int i = 0; i < n-1; i++) {
		if (ss[i] == 'S' && ss[i+1] == 'F') s += 1;
		if (ss[i] == 'F' && ss[i+1] == 'S') f += 1;
	}
	if (s > f) cout << "YES" << endl;
	else cout << "NO" << endl;
}
