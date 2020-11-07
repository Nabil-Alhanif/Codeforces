#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, need;
	cin >> n;
	int ar[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> ar[i][j];
		}
	}
	cin >> p;
	for (int k = 0; k < n; k++) {
		if (p >= ar[k][0] && p <= ar[k][1]) {
			need = n-k;
		}
	}
	cout << need << endl;
}
