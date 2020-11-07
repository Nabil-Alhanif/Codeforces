#include <bits/stdc++.h>
using namespace std;

int main() {
	bool can = false;
	int n, a=-1, b, c;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				if (ar[i]==ar[j]+ar[k]) {
					can = true;
					a = k+1;
					b = j+1;
					c = i+1;
					break;
				}
			}
		}
	}
	if (can) cout << c << " " << b << " " << a << endl;
	else cout << -1 << endl;
}
