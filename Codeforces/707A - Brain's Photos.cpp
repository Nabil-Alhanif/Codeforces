#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool black=true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c=='C'||c=='M'||c=='Y') {
				black=false;
			}
		}
	}
	if (black)cout << "#Black&White\n";
	else cout << "#Color\n";
}
