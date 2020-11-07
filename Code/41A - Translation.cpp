#include <bits/stdc++.h>
using namespace std;

int main() {
	bool did = true;
	string s, s2;
	cin >> s >> s2;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (s[i] != s2[size-1-i]) {
			did = false;
			break;
		}
	}
	if (did) cout << "YES" << endl;
	else cout << "NO" << endl;
}
