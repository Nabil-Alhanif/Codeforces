#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	map<int, int> m;
	int t;
	cin >> t;
	int a, b;
	cin >> a;
	while (a--) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	cin >> b;
	while (b--) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	if (m.size()==t)cout << "I become the guy.\n";
	else cout << "Oh, my keyboard!\n";
}
