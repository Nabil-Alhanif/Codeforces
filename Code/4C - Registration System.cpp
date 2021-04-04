#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	map<string, int> m;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		m[s]++;
		if (m[s]==1)cout << "OK\n";
		else {
			cout << s << m[s]-1 << "\n";
		}
	}
}
