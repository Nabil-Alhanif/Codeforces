#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort (ar, ar+n);
		bool dua = false;
		for (int i= 0; i < n-1; i++) {
			if (ar[i]==ar[i+1]-1) {
				dua = true;
				break;
			}
		}
		if (dua) cout << 2 << "\n";
		else cout << 1 << "\n";
	}
}
