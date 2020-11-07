#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string s[n], t[m];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	long test;
	cin >> test;
	while (test--) {
		long tmp;
		cin >> tmp;
		long stmp = tmp%n;
		if (stmp==0)stmp=n;
		long ttmp = tmp%m;
		if (ttmp==0)ttmp=m;
		cout << s[stmp-1] << t[ttmp-1] << "\n";
	}
}
