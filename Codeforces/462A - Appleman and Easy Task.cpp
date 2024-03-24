#include <bits/stdc++.h>
using namespace std;

int main() {
	bool bisa = true;
	int n;
	cin >> n;
	char ar[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int count = 0;
			if (i-1>=0) {
				if (ar[i-1][j]=='o') count++;
			}
			if (i+1<n) {
				if (ar[i+1][j]=='o') count++;
			}
			if (j-1>=0) {
				if (ar[i][j-1]=='o') count++;
			}
			if (j+1<n) {
				if (ar[i][j+1]=='o') count++;
			}
			if (count%2==1) {
				bisa = false;
				break;
			}
		}
		if (!bisa) break;
	}
	if (bisa) cout << "YES\n";
	else cout << "NO\n";
}
