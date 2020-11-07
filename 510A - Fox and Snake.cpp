#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		if (i%2 == 1) {
			for (int j = 0; j < m; j++) {
				cout << "#";
			}
			cout << endl;
		}
		if (i%2 == 0) {
			if (i%4==0) cout << "#";
			for (int k = 1; k < m; k++) {
				cout << ".";
			}
			if (i%4 != 0) cout << "#";
			cout << endl;
		}
	}
}
