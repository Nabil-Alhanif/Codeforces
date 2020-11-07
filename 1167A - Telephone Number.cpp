#include <bits/stdc++.h>
using namespace std;

string check() {
	int n, index;
	bool tel = false;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') {
			tel = true;
			index = i;
			break;
		}
	}
	if (tel && n-index >= 11) {
		return "YES";
	} else return "NO";
}

int main() {
	int t;
	cin >> t;
	string ar[t];
	for (int i = 0; i < t; i++) {
		ar[i] = check();
	}
	for (int j = 0; j < t; j++) {
		cout << ar[j] << endl;
	}
}
