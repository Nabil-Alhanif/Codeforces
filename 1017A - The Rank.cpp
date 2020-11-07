#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n][4];
	int ar2[n] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> ar[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		int z = 0;
		while (z < 4) {
			ar2[k] += ar[k][z];
			z++;
		}
	}
	int t = ar2[0];
	sort(ar2, ar2+n);
	for (int l = n-1; l >= 0; l--) {
		if (ar2[l] == t) {
			int temp = n-l;
			cout << temp << endl;
			break;
		}
	}
}
